#include "proportion.h"

#include <QCheckBox>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>

#include <QRadioButton>

Proportion::Proportion()
    : horizontal_layout_(new QHBoxLayout),
      grid_layout_(new QGridLayout),
      font_(new QFont) {}

Proportion::~Proportion() { delete font_; }

void Proportion::SetProportion(QRadioButton *programming_button,
                               QRadioButton *office_button,
                               QRadioButton *moto_button,
                               QCheckBox *state_checkbox,
                               QLineEdit *coefficient_line,
                               QLabel *number_label, QLineEdit *edit_line,
                               QLabel *result_label, QLCDNumber *lcd) {
  SetWidgetAppearance(coefficient_line, edit_line, lcd, programming_button);
  SetHorizontalLayout(programming_button, office_button, moto_button,
                      state_checkbox, coefficient_line);
  SetGridLayout(number_label, edit_line, result_label, lcd);
  SetWidgetFont(number_label, result_label, coefficient_line, edit_line, lcd);
}

QGridLayout *Proportion::GridLayout() { return grid_layout_; }

void Proportion::SetWidgetAppearance(QLineEdit *coefficient_line,
                                     QLineEdit *edit_line, QLCDNumber *lcd,
                                     QRadioButton *button1) {
  coefficient_line->setEnabled(false);
  coefficient_line->setAlignment(Qt::AlignRight);
  coefficient_line->setFixedSize(75, 25);
  edit_line->setAlignment(Qt::AlignRight);

  lcd->setAutoFillBackground(true);
  lcd->setSegmentStyle(QLCDNumber::Flat);
  lcd->setFrameStyle(QFrame::NoFrame);

  button1->setChecked(true);
}

void Proportion::SetHorizontalLayout(QRadioButton *button1,
                                     QRadioButton *button2,
                                     QRadioButton *button3,
                                     QCheckBox *state_checkbox,
                                     QLineEdit *coefficient_line) {
  horizontal_layout_->addWidget(button1, 1, Qt::AlignLeft);
  horizontal_layout_->addWidget(button2, 1, Qt::AlignLeft);
  horizontal_layout_->addWidget(button3, 1, Qt::AlignLeft);

  horizontal_layout_->addWidget(state_checkbox, 1, Qt::AlignRight);

  horizontal_layout_->addWidget(coefficient_line);
  horizontal_layout_->setSpacing(1);
}

void Proportion::SetGridLayout(QLabel *number_label, QLineEdit *edit_line,
                               QLabel *result_label, QLCDNumber *lcd) {
  grid_layout_->addLayout(horizontal_layout_, 1, 0, 1, 2);
  grid_layout_->addWidget(number_label, 2, 1);
  grid_layout_->addWidget(edit_line, 3, 1);
  grid_layout_->addWidget(result_label, 4, 0, 2, 2);
  grid_layout_->addWidget(lcd, 6, 1, 1, 2);
}

void Proportion::SetWidgetFont(QLabel *number_label, QLabel *result_label,
                               QLineEdit *coefficient_line,
                               QLineEdit *edit_line, QLCDNumber *lcd) {
  SetFont(number_label, 14);
  SetFont(result_label, 16);

  SetFont(coefficient_line, 12);
  SetFont(edit_line, 14);

  SetFont(lcd, 10);
}

void Proportion::SetFont(QWidget *widget, int font_size) {
  widget->setFont(Font(font_size));
}

const QFont &Proportion::Font(int font_size) {
  font_->setPointSize(font_size);
  return *font_;
}
