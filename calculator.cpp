#include "calculator.h"

#include <cmath>

#include <QApplication>
#include <QCheckBox>
#include <QClipboard>
#include <QGridLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent),
      clipboard_(QApplication::clipboard()),
      coefficient_line_(new QLineEdit),
      value_line_(new QLineEdit),
      lcd_(new QLCDNumber(16)) {
  line_styler_.SetCoefficientLine(coefficient_line_);
  line_styler_.SetValueLine(value_line_);
  lcd_styler_.SetLCDNumber(lcd_);

  QLabel *coefficient_label_ = label_styler_.GetLabel("Coefficient:");
  QLabel *result_label = label_styler_.GetLabel("Result:", 14);
  QCheckBox *coefficient_checkbox = checkbox_styler_.GetCheckBox();

  layout_.SetHorizontalLayout(coefficient_label_, coefficient_checkbox,
                              coefficient_line_);
  layout_.SetGridLayout(value_line_, result_label, lcd_);

  connect(value_line_, SIGNAL(returnPressed()), value_line_, SLOT(clear()));
  connect(value_line_, SIGNAL(textChanged(QString)),
          SLOT(CalculateResult(QString)));
  connect(this, SIGNAL(CompletedDoubleValue(double)), lcd_,
          SLOT(display(double)));
  connect(coefficient_checkbox, SIGNAL(clicked(bool)), coefficient_line_,
          SLOT(setEnabled(bool)));

  SetMainWindow(layout_.GetLayout());
}

void Calculator::CalculateResult(const QString &value) {
  multipyer_.SetCoefficient(coefficient_line_->text().toDouble());
  multipyer_.SetNumber(value);

  clipboard_->setText(multipyer_.GetCompleteStringValue());

  emit CompletedDoubleValue(multipyer_.GetCompleteDoubleValue());
}

void Calculator::SetMainWindow(QGridLayout *layout) {
  setLayout(layout);
  setFixedSize(210, 160);
  setWindowTitle("Calculator");
  setStyleSheet("background-color:black;");
}
