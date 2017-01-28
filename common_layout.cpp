#include "common_layout.h"

#include <QCheckBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>

CommonLayout::CommonLayout()
    : grid_layout_(new QGridLayout), horizontal_layout_(new QHBoxLayout) {}

QGridLayout *CommonLayout::GetLayout() { return grid_layout_; }

void CommonLayout::SetGridLayout(QLineEdit *line_edit, QLabel *label,
                                 QLCDNumber *lcd) {
  grid_layout_->addLayout(horizontal_layout_, 0, 0, 1, 2);
  grid_layout_->addWidget(line_edit, 1, 1);
  grid_layout_->addWidget(label, 2, 0, 2, 2);
  grid_layout_->addWidget(lcd, 4, 1, 1, 2);
  grid_layout_->setSpacing(1);
}

void CommonLayout::SetHorizontalLayout(QLabel *label, QCheckBox *checkbox,
                                       QLineEdit *line_edit) {
  horizontal_layout_->addWidget(label);
  horizontal_layout_->addWidget(checkbox);
  horizontal_layout_->addWidget(line_edit);
}
