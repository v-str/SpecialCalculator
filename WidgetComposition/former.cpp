#include "former.h"

Former::Former()
    : number_label_(new QLabel),
      result_label_(new QLabel),
      coefficient_line_(new QLineEdit("1.18")),
      edit_line_(new QLineEdit),
      state_checkbox_(new QCheckBox),
      lcd_(new QLCDNumber(16)),
      propotion_(new Proportion),
      programming_button1_(new QRadioButton),
      office_button2_(new QRadioButton),
      moto_button3_(new QRadioButton) {
  propotion_->SetProportion(programming_button1_, office_button2_,
                            moto_button3_, state_checkbox_, coefficient_line_,
                            number_label_, edit_line_, result_label_, lcd_);
}

Former::~Former() {
  delete number_label_;
  delete result_label_;
  delete coefficient_line_;
  delete edit_line_;
  delete state_checkbox_;
  delete lcd_;
  delete propotion_;
  delete programming_button1_;
  delete office_button2_;
  delete moto_button3_;
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

QLCDNumber *Former::LCDNumber() const { return lcd_; }

QGridLayout *Former::GridLayout() const { return propotion_->GridLayout(); }

QRadioButton *Former::Button1() const { return programming_button1_; }

QRadioButton *Former::Button2() const { return office_button2_; }

QRadioButton *Former::Button3() const { return moto_button3_; }
