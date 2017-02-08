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
      radio_layout_(new QHBoxLayout),
      horizontal_layout_(new QHBoxLayout),
      grid_layout_(new QGridLayout),
      font_(new QFont)

{
  SetWidgetFont();
  SetLayout();
  SetWidgetAppearance();  // Move in separate class.
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

QGridLayout *Former::GridLayout() const { return grid_layout_; }

void Former::SetWidgetFont() {
  SetFont(number_label_, 14);
  SetFont(result_label_, 16);

  SetFont(coefficient_line_, 12);
  SetFont(edit_line_, 14);

  SetFont(lcd_, 10);
}

void Former::SetLayout() {
  horizontal_layout_->addWidget(programmer_style_checkbox_, 1, Qt::AlignRight);
  horizontal_layout_->addWidget(office_style_checkbox_, 1, Qt::AlignRight);
  horizontal_layout_->addWidget(moto_style_checkbox_, 1, Qt::AlignRight);
  horizontal_layout_->addWidget(state_checkbox_, 1, Qt::AlignRight);

  horizontal_layout_->addWidget(coefficient_line_);
  horizontal_layout_->setSpacing(1);

  grid_layout_->addLayout(radio_layout_, 0, 0, 1, 0, Qt::AlignLeft);
  grid_layout_->addLayout(horizontal_layout_, 1, 0, 1, 2);
  grid_layout_->addWidget(number_label_, 2, 1);
  grid_layout_->addWidget(edit_line_, 3, 1);
  grid_layout_->addWidget(result_label_, 4, 0, 2, 2);
  grid_layout_->addWidget(lcd_, 6, 1, 1, 2);
}

void Former::SetWidgetAppearance() {
  coefficient_line_->setAlignment(Qt::AlignRight);
  coefficient_line_->setFixedSize(75, 25);
  edit_line_->setAlignment(Qt::AlignRight);

  lcd_->setAutoFillBackground(true);
  lcd_->setSegmentStyle(QLCDNumber::Flat);
  lcd_->setFrameStyle(QFrame::NoFrame);

  programmer_style_checkbox_->setChecked(true);
}

template <typename Widget>
void Former::SetFont(Widget *widget, int font_size) {
  widget->setFont(Font(font_size));
}

const QFont &Former::Font(int size) {
  font_->setPointSize(size);
  return *font_;
}
