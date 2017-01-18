#include "calculator.h"

#include <sstream>

#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPalette>

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
  /// Эксперементальная часть.
  /// Отображение не через LCD, а через LineEdit

  QPalette *result_line_palette = new QPalette;
  result_line_palette->setColor(QPalette::Base, Qt::black);
  result_line_palette->setColor(QPalette::Text, Qt::green);

  result_line_ = new QLineEdit;
  result_line_->setPalette(*result_line_palette);
  result_line_->setAlignment(Qt::AlignRight);

  // Палитра для LCD дисплея
  QPalette *lcd_palette = new QPalette;
  lcd_palette->setColor(QPalette::Text, Qt::green);
  lcd_palette->setColor(QPalette::Background, Qt::black);
  lcd_palette->setColor(QPalette::Foreground, Qt::green);

  // Сам LCD дисплей
  lcd_ = new QLCDNumber(16);
  lcd_->setAutoFillBackground(true);
  lcd_->setSegmentStyle(QLCDNumber::Flat);
  lcd_->setPalette(*lcd_palette);
  lcd_->setFrameStyle(QFrame::NoFrame);

  // Палитра для поля "коэффициент умножения"
  QPalette *line_edit_palette = new QPalette;
  line_edit_palette->setColor(QPalette::Base, Qt::black);
  line_edit_palette->setColor(QPalette::Text, Qt::green);

  // поле класса, в которое заносится коэффициент умножения
  coefficient_line_ = new QLineEdit;
  coefficient_line_->setAlignment(Qt::AlignRight);
  coefficient_line_->setText("1.18");
  coefficient_line_->setMaximumSize(75, 25);
  coefficient_line_->setFrame(QFrame::WinPanel);
  coefficient_line_->setPalette(*line_edit_palette);

  // поле класса, в которое заносится коэффициент умножения
  value_line_ = new QLineEdit;
  value_line_->setAlignment(Qt::AlignRight);
  value_line_->setPalette(*line_edit_palette);

  // Шрифт для лэйблов
  QFont *label_font = new QFont;
  label_font->setPointSize(14);

  // Лэйбл "Коэффициент"
  QLabel *coefficient_label_ = new QLabel;
  coefficient_label_->setText("<font color='green'>Coefficient:</font>");
  coefficient_label_->setFont(*label_font);
  coefficient_label_->setAlignment(Qt::AlignRight);

  // Лэйбл "Результат"
  QLabel *result_label = new QLabel;
  result_label->setText("<font color='green'>Result:</font>");
  result_label->setFont(*label_font);
  result_label->setAlignment(Qt::AlignBottom | Qt::AlignLeft);

  // Горизонтальный менеджер компоновки. В него помещаем
  // лэйбл "Коэффициент" и поле для ввода коеэффициента
  QHBoxLayout *horizontal_layout = new QHBoxLayout;
  horizontal_layout->setSpacing(5);
  horizontal_layout->addWidget(coefficient_label_);
  horizontal_layout->addWidget(coefficient_line_);

  // Менеджер компоновки "Сетка". Заносим в него уже имеющийся
  // менеджер горизонтальной компоновки, а так же остальные лэйблы и
  // поля класса.
  QGridLayout *layout = new QGridLayout;
  layout->addLayout(horizontal_layout, 0, 0, 1, 2);
  layout->addWidget(value_line_, 1, 1);
  layout->addWidget(result_label, 2, 0, 1, 2);
  layout->addWidget(lcd_, 3, 1);
  layout->addWidget(result_line_, 4, 1);
  layout->setSpacing(1);

  // Соединяем поле "Значение от пользователя" с самим собой
  connect(value_line_, SIGNAL(returnPressed()), value_line_, SLOT(clear()));
  connect(value_line_, SIGNAL(returnPressed()), result_line_, SLOT(clear()));

  // Соединяем поле "Значение от пользователя" с СЛОТОМ ЭТОГО же класса(мой
  // слот)
  connect(value_line_, SIGNAL(textChanged(QString)), SLOT(GetResult(QString)));

  // Соединяем ЭТОТ ОБЪЕКТ с помощью НОВОГО сигнала(мой сигнал) с LCD дисплеем
  connect(this, SIGNAL(CompletedDoubleValue(double)), lcd_,
          SLOT(display(double)));

  /// эксперимент
  /// Отправка сигнала из моего объекта к слоту моего же
  /// объекта, который потом отображает результат в result_line_
  connect(this, SIGNAL(CompletedDoubleValue(double)),
          SLOT(DisplayResult(double)));

  // Задаем компоновку для объекта, передаем менеджер "Сетка"
  setLayout(layout);
}

// Метод, вычисляющий значение "Коэффициета * значение от пользователя"
void Calculator::GetResult(QString value) {
  // Получаем из полей текстовое значение и потом преобразуем его к типу double
  double multiply_coefficient = coefficient_line_->text().toDouble();
  double number = value.toDouble();

  // Вычисление результата
  double complete_double_value_ = number * multiply_coefficient;

  // Дублирование для отображения в QLineEdit
  QString complete_qstring_value =
      QString::fromStdString(GetString(complete_double_value_));

  // Отправка сигнала с полученным результатом умножения
  emit CompletedDoubleValue(complete_double_value_);
  emit CompleteQStringValue(complete_qstring_value);
}

// Отображение в result_line_ с точностью до 2 знаков после запятой
void Calculator::DisplayResult(double result) {
  result_line_->clear();
  result_line_->setText(QString::number(result, 'f', 2));
}

std::string Calculator::GetString(double value) {
  std::stringstream convert_stream;
  convert_stream << value;

  return convert_stream.str();
}
