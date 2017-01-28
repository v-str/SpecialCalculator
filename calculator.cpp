#include "calculator.h"

#include <cmath>

#include <QApplication>
#include <QCheckBox>
#include <QClipboard>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>
#include <QPalette>
#include <QTextEdit>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent),
      clipboard_(QApplication::clipboard()),
      coefficient_line_(new QLineEdit),
      value_line_(new QLineEdit),
      lcd_(new QLCDNumber(16)) {
  SetCoefficientLine(coefficient_line_);
  SetValueLine(value_line_);
  SetLCDNumber(lcd_);

  QLabel *coefficient_label_ = label_styler_.GetLabel("Coefficient:");
  QLabel *result_label = label_styler_.GetLabel("Result:", 14);
  QCheckBox *coefficient_checkbox = checkbox_styler_.GetCheckBox();

  QHBoxLayout *horizontal_layout = new QHBoxLayout;
  SetHorizontalLayout(horizontal_layout, coefficient_label_,
                      coefficient_checkbox, coefficient_line_);

  QGridLayout *grid_layout = new QGridLayout;
  SetGridLayout(grid_layout, horizontal_layout, value_line_, result_label,
                lcd_);

  connect(value_line_, SIGNAL(returnPressed()), value_line_, SLOT(clear()));
  connect(value_line_, SIGNAL(textChanged(QString)),
          SLOT(CalculateResult(QString)));
  connect(this, SIGNAL(CompletedDoubleValue(double)), lcd_,
          SLOT(display(double)));
  connect(coefficient_checkbox, SIGNAL(clicked(bool)), coefficient_line_,
          SLOT(setEnabled(bool)));

  SetMainWindow(grid_layout);
}

void Calculator::CalculateResult(const QString &value) {
  double multiply_coefficient = coefficient_line_->text().toDouble();
  double number = value.toDouble();

  complete_value_ = number * multiply_coefficient;

  complete_value_ = round(complete_value_ * 100) / 100;

  QString complete_qstring_value = QString::number(complete_value_);

  clipboard_->setText(complete_qstring_value);

  emit CompletedDoubleValue(complete_value_);
  emit CompleteQStringValue(complete_qstring_value);
}

void Calculator::SetMainWindow(QGridLayout *layout) {
  setLayout(layout);
  setFixedSize(210, 160);
  setWindowTitle("Calculator");
  setStyleSheet("background-color:black;");
}

void Calculator::SetCoefficientLine(QLineEdit *coefficient_line) {
  coefficient_line->setDisabled(true);
  coefficient_line->setAlignment(Qt::AlignRight);
  coefficient_line->setText("1.18");
  coefficient_line->setMaximumSize(75, 25);
  SetLineEditStyle(coefficient_line);
}

void Calculator::SetLineEditStyle(QLineEdit *line) {
  line->setStyleSheet(
      "QLineEdit {"
      "border: 1px solid green;"
      "border-radius: 7px;"
      "background: black;"
      "selection-background-color: #40494D;"
      "color: green;"
      "font-weight: bold;"
      "}");
}

void Calculator::SetValueLine(QLineEdit *value_line) {
  value_line->setAlignment(Qt::AlignRight);
  SetLineEditStyle(value_line_);
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

void Calculator::SetHorizontalLayout(QHBoxLayout *layout, QLabel *label,
                                     QCheckBox *checkbox,
                                     QLineEdit *line_edit) {
  layout->addWidget(label);
  layout->addWidget(checkbox);
  layout->addWidget(line_edit);
}

void Calculator::SetGridLayout(QGridLayout *grid_layout, QHBoxLayout *layout,
                               QLineEdit *line_edit, QLabel *label,
                               QLCDNumber *lcd) {
  grid_layout->addLayout(layout, 0, 0, 1, 2);
  grid_layout->addWidget(line_edit, 1, 1);
  grid_layout->addWidget(label, 2, 0, 2, 2);
  grid_layout->addWidget(lcd, 4, 1, 1, 2);
  grid_layout->setSpacing(1);
}
