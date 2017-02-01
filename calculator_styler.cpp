#include "calculator_styler.h"

#include "checkbox_styler.h"
#include "common_layout.h"
#include "label_styler.h"
#include "lcd_styler.h"
#include "line_styler.h"

#include <QCheckBox>
#include <QGridLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>

CalculatorStyler::CalculatorStyler()
    : coefficient_line_(new QLineEdit),
      value_line_(new QLineEdit),
      lcd_(new QLCDNumber(16)),
      label_styler_(new LabelStyler),
      checkbox_styler_(new CheckBoxStyler),
      line_styler_(new LineStyler),
      lcd_styler_(new LcdStyler),
      layout_(new CommonLayout) {}

CalculatorStyler::~CalculatorStyler() {
  delete coefficient_line_;
  delete value_line_;
  delete lcd_;
  delete label_styler_;
  delete checkbox_styler_;
  delete line_styler_;
  delete lcd_styler_;
  delete layout_;
}

void CalculatorStyler::SetStyle(CalculatorStyler::AppTheme theme) {
  if (theme == kProgrammer) {
    line_styler_->SetCoefficientLine(coefficient_line_);
    line_styler_->SetValueLine(value_line_);
    lcd_styler_->SetLCDNumber(lcd_);

    layout_->SetHorizontalLayout(label_styler_->GetLabel("Coefficient:"),
                                 checkbox_styler_->GetCheckBox(),
                                 coefficient_line_);

    layout_->SetGridLayout(value_line_, label_styler_->GetLabel("Result:", 14),
                           lcd_);
  }
}

QLineEdit *CalculatorStyler::GetCoefficientLine() const {
  return coefficient_line_;
}

QLineEdit *CalculatorStyler::GetValueLine() const { return value_line_; }

QLCDNumber *CalculatorStyler::GetLCD() const { return lcd_; }

CheckBoxStyler *CalculatorStyler::GetCheckBoxStyler() const {
  return checkbox_styler_;
}
