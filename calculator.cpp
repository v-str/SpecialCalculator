#include "calculator.h"

#include <sstream>

#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPalette>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent),
      coefficient_line_(new QLineEdit),
      value_line_(new QLineEdit),
      lcd_(new QLCDNumber(16)),
      result_line_(new QLineEdit) {
  SetCoefficientLine(coefficient_line_);

  value_line_->setAlignment(Qt::AlignRight);
  SetPaletteForLineEdit(value_line_);

  result_line_->setAlignment(Qt::AlignRight);
  SetPaletteForLineEdit(result_line_);

  SetLCDNumber(lcd_);

  QFont *label_font = new QFont;
  label_font->setPointSize(14);

  QLabel *coefficient_label_ = new QLabel;
  coefficient_label_->setText("<font color='green'>Coefficient:</font>");
  coefficient_label_->setFont(*label_font);

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

  complete_value_ = number * multiply_coefficient;

  QString complete_qstring_value = QString::number(complete_value_);

  emit CompletedDoubleValue(complete_value_);
  emit CompleteQStringValue(complete_qstring_value);
}

void Calculator::DisplayResult(double result) {
  result_line_->clear();
  result_line_->setText(QString::number(result, 'f', 2));
}

void Calculator::SetCoefficientLine(QLineEdit *coefficient_line) {
  coefficient_line->setAlignment(Qt::AlignRight);
  coefficient_line->setText("1.18");
  coefficient_line->setMaximumSize(75, 25);
  SetPaletteForLineEdit(coefficient_line);
}

void Calculator::SetPaletteForLineEdit(QLineEdit *line) {
  QPalette line_edit_palette;
  line_edit_palette.setColor(QPalette::Base, Qt::black);
  line_edit_palette.setColor(QPalette::Text, Qt::green);

  line->setPalette(line_edit_palette);
}

void Calculator::SetPaletteForLCD(QLCDNumber *lcd) {
  QPalette lcd_palette;
  lcd_palette.setColor(QPalette::Text, Qt::green);
  lcd_palette.setColor(QPalette::Background, Qt::black);
  lcd_palette.setColor(QPalette::Foreground, Qt::green);

  lcd->setPalette(lcd_palette);
}

void Calculator::SetLCDNumber(QLCDNumber *lcd) {
  lcd->setAutoFillBackground(true);
  lcd->setSegmentStyle(QLCDNumber::Flat);
  lcd->setFrameStyle(QFrame::NoFrame);

  SetPaletteForLCD(lcd);
}
