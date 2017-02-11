#include "former.h"

Former::Former()
    : number_label_(new QLabel),
      result_label_(new QLabel),
      coefficient_line_(new QLineEdit("1.18")),
      edit_line_(new QLineEdit),
      state_checkbox_(new QCheckBox),
      programmer_style_checkbox_(new QCheckBox),
      office_style_checkbox_(new QCheckBox),
      moto_style_checkbox_(new QCheckBox),
      lcd_(new QLCDNumber(16)),
      propotion_(new Proportion)

{
  propotion_->SetProportion(programmer_style_checkbox_, office_style_checkbox_,
                            moto_style_checkbox_, state_checkbox_,
                            coefficient_line_, number_label_, edit_line_,
                            result_label_, lcd_);
}

Former::~Former() {
  delete number_label_;
  delete result_label_;
  delete coefficient_line_;
  delete edit_line_;
  delete state_checkbox_;
  delete programmer_style_checkbox_;
  delete office_style_checkbox_;
  delete moto_style_checkbox_;
  delete lcd_;
  delete propotion_;
}

QLabel *Former::NumberLabel() const {
  number_label_->setText("Number:");
  return number_label_;
}

QLabel *Former::ResultLabel() const {
  result_label_->setText("Result:");
  return result_label_;
}

QLineEdit *Former::CoefficientLine() const { return coefficient_line_; }

QLineEdit *Former::EditLine() const { return edit_line_; }

QCheckBox *Former::StateCheckBox() const { return state_checkbox_; }

QCheckBox *Former::ProgrammerCheckBox() const {
  return programmer_style_checkbox_;
}

QCheckBox *Former::OfficeCheckBox() const { return office_style_checkbox_; }

QCheckBox *Former::MotoCheckBox() const { return moto_style_checkbox_; }

QLCDNumber *Former::LCDNumber() const { return lcd_; }

QGridLayout *Former::GridLayout() const { return propotion_->GridLayout(); }
