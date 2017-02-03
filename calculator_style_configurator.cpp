#include "calculator_style_configurator.h"

#include "checkbox_style_configurator.h"
#include "common_layout.h"
#include "label_style_configurator.h"
#include "lcd_style_configurator.h"
#include "line_style_configurator.h"

#include <QCheckBox>
#include <QGridLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>

CaclulatorStyleConfigurator::CaclulatorStyleConfigurator()
    : coefficient_line_(new QLineEdit),
      value_line_(new QLineEdit),
      lcd_(new QLCDNumber(16)),
      label_styler_(new LabelStyleConfigurator),
      checkbox_styler_(new CheckBoxStyleConfigurator),
      line_styler_(new LineStyleConfigurator),
      lcd_styler_(new LcdStyleConfigurator),
      layout_(new CommonLayout) {
  coefficient_label_ = label_styler_->GetLabel("Coefficient:");
  result_label_ = label_styler_->GetLabel("Result:", 14);
  coefficient_checkbox_ = checkbox_styler_->GetCheckBox();
}

void CaclulatorStyleConfigurator::SetStyle(
    CaclulatorStyleConfigurator::AppTheme theme) {
  if (theme == kProgrammer) {
    line_styler_->SetCoefficientLine(coefficient_line_);
    line_styler_->SetValueLine(value_line_);
    lcd_styler_->SetLCDNumber(lcd_);

    layout_->SetHorizontalLayout(coefficient_label_, coefficient_checkbox_,
                                 coefficient_line_);

    layout_->SetGridLayout(value_line_, result_label_, lcd_);
  }
}

QLineEdit *CaclulatorStyleConfigurator::GetValueLine() { return value_line_; }

QLCDNumber *CaclulatorStyleConfigurator::GetLCDNumber() { return lcd_; }

QLineEdit *CaclulatorStyleConfigurator::GetCoefficientLine() {
  return coefficient_line_;
}

QCheckBox *CaclulatorStyleConfigurator::GetCoefficientCheckBox() {
  return coefficient_checkbox_;
}

QGridLayout *CaclulatorStyleConfigurator::GetLayout() {
  return layout_->GetLayout();
}
