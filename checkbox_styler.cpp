#include "checkbox_styler.h"

#include <QCheckBox>

QCheckBox *CheckBoxStyler::GetCheckBox() {
  QCheckBox *checkbox = new QCheckBox;
  SetCheckBoxStyle(checkbox);
  return checkbox;
}

void CheckBoxStyler::SetCheckBoxStyle(QCheckBox *checkbox) {
  checkbox->setStyleSheet(
      "QCheckBox::indicator:unchecked {"
      "border: 3px solid #084913;"
      "border-radius: 5px;"
      "background-color: black;"
      "}"
      "QCheckBox::indicator:checked {"
      "border: 3px solid #084913;"
      "border-radius: 5px;"
      "background-color: #367240;"
      "}");
}
