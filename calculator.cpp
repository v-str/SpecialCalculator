#include "calculator.h"

#include <sstream>

#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPalette>

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
  QPalette *result_line_palette = new QPalette;
  result_line_palette->setColor(QPalette::Base, Qt::black);
  result_line_palette->setColor(QPalette::Text, Qt::green);

  result_line_ = new QLineEdit;
  result_line_->setPalette(*result_line_palette);
  result_line_->setAlignment(Qt::AlignRight);

  QPalette *lcd_palette = new QPalette;
  lcd_palette->setColor(QPalette::Text, Qt::green);
  lcd_palette->setColor(QPalette::Background, Qt::black);
  lcd_palette->setColor(QPalette::Foreground, Qt::green);

  lcd_ = new QLCDNumber(16);
  lcd_->setAutoFillBackground(true);
  lcd_->setSegmentStyle(QLCDNumber::Flat);
  lcd_->setPalette(*lcd_palette);
  lcd_->setFrameStyle(QFrame::NoFrame);

  QPalette *line_edit_palette = new QPalette;
  line_edit_palette->setColor(QPalette::Base, Qt::black);
  line_edit_palette->setColor(QPalette::Text, Qt::green);

  coefficient_line_ = new QLineEdit;
  coefficient_line_->setAlignment(Qt::AlignRight);
  coefficient_line_->setText("1.18");
  coefficient_line_->setMaximumSize(75, 25);
  coefficient_line_->setFrame(QFrame::WinPanel);
  coefficient_line_->setPalette(*line_edit_palette);

  value_line_ = new QLineEdit;
  value_line_->setAlignment(Qt::AlignRight);
  value_line_->setPalette(*line_edit_palette);

  QFont *label_font = new QFont;
  label_font->setPointSize(14);

  QLabel *coefficient_label_ = new QLabel;
  coefficient_label_->setText("<font color='green'>Coefficient:</font>");
  coefficient_label_->setFont(*label_font);
  coefficient_label_->setAlignment(Qt::AlignRight);

  QLabel *result_label = new QLabel;
  result_label->setText("<font color='green'>Result:</font>");
  result_label->setFont(*label_font);
  result_label->setAlignment(Qt::AlignBottom | Qt::AlignLeft);

  QHBoxLayout *horizontal_layout = new QHBoxLayout;
  horizontal_layout->setSpacing(5);
  horizontal_layout->addWidget(coefficient_label_);
  horizontal_layout->addWidget(coefficient_line_);

  QGridLayout *layout = new QGridLayout;
  layout->addLayout(horizontal_layout, 0, 0, 1, 2);
  layout->addWidget(value_line_, 1, 1);
  layout->addWidget(result_label, 2, 0, 1, 2);
  layout->addWidget(lcd_, 3, 1);
  layout->addWidget(result_line_, 4, 1);
  layout->setSpacing(1);

  connect(value_line_, SIGNAL(returnPressed()), value_line_, SLOT(clear()));
  connect(value_line_, SIGNAL(returnPressed()), result_line_, SLOT(clear()));
  connect(value_line_, SIGNAL(textChanged(QString)),
          SLOT(CalculateResult(QString)));
  connect(this, SIGNAL(CompletedDoubleValue(double)), lcd_,
          SLOT(display(double)));
  connect(this, SIGNAL(CompletedDoubleValue(double)),
          SLOT(DisplayResult(double)));

  setLayout(layout);
}

void Calculator::CalculateResult(const QString &value) {
  double multiply_coefficient = coefficient_line_->text().toDouble();
  double number = value.toDouble();

  double complete_double_value_ = number * multiply_coefficient;

  QString complete_qstring_value = QString::number(complete_double_value_);

  emit CompletedDoubleValue(complete_double_value_);
  emit CompleteQStringValue(complete_qstring_value);
}

void Calculator::DisplayResult(double result) {
  result_line_->clear();
  result_line_->setText(QString::number(result, 'f', 2));
}
