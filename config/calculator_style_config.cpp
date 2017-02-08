#include "calculator_style_config.h"

#include "checkbox_styler.h"

CaclulatorStyleConfig::CaclulatorStyleConfig()
    : coefficient_line_(new QLineEdit("1.18")),
      value_line_(new QLineEdit),
      lcd_(new QLCDNumber(16)),
      coefficient_label_(new QLabel),
      number_label_(new QLabel),
      result_label_(new QLabel),
      coefficient_checkbox_(new QCheckBox),
      grid_layout_(new QGridLayout),
      horizontal_layout_(new QHBoxLayout),
      line_edit_styler(new LineEditStyler),
      lcd_styler_(new LCDStyler),
      label_styler_(new LabelStyler) {}

void CaclulatorStyleConfig::SetStyle(config::Theme theme) {
  line_edit_styler->SetCoefficientLine(coefficient_line_, theme);
  line_edit_styler->SetValueLine(value_line_, theme);

  lcd_styler_->SetLCDNumber(lcd_, theme);

  label_styler_->SetLabel(coefficient_label_, "Coefficient", 10, theme);
  label_styler_->SetLabel(number_label_, "Number:", 14, theme);
  label_styler_->SetLabel(result_label_, "Result:", 16, theme);
  CheckBoxStyler::SetCheckBox(coefficient_checkbox_, theme);

  SetHorizontalLayout(horizontal_layout_, coefficient_label_,
                      coefficient_checkbox_, coefficient_line_);

  SetGridLayout(grid_layout_, number_label_, value_line_, result_label_, lcd_);
}

QLineEdit *CaclulatorStyleConfig::GetValueLine() { return value_line_; }

QLineEdit *CaclulatorStyleConfig::GetCoefficientLine() {
  return coefficient_line_;
}

QLCDNumber *CaclulatorStyleConfig::GetLCDNumber() { return lcd_; }

QCheckBox *CaclulatorStyleConfig::GetCoefficientCheckBox() {
  return coefficient_checkbox_;
}

QGridLayout *CaclulatorStyleConfig::GetLayout() { return grid_layout_; }

void CaclulatorStyleConfig::SetGridLayout(QGridLayout *grid_layout,
                                          QLabel *number_label,
                                          QLineEdit *line_edit,
                                          QLabel *result_label,
                                          QLCDNumber *lcd) {
  grid_layout->addLayout(horizontal_layout_, 0, 0, 1, 2);
  grid_layout->addWidget(number_label, 1, 1);
  grid_layout->addWidget(line_edit, 2, 1);
  grid_layout->addWidget(result_label, 3, 0, 2, 2);
  grid_layout->addWidget(lcd, 5, 1, 1, 2);
  grid_layout->setSpacing(1);
}

void CaclulatorStyleConfig::SetHorizontalLayout(QHBoxLayout *layout,
                                                QLabel *label,
                                                QCheckBox *checkbox,
                                                QLineEdit *line_edit) {
  layout->addWidget(label);
  layout->addWidget(checkbox, 1, Qt::AlignRight);
  layout->addWidget(line_edit);
}
