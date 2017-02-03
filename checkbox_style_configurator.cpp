#include "checkbox_style_configurator.h"

#include <QCheckBox>

QCheckBox *CheckBoxStyleConfigurator::GetCheckBox() {
  QCheckBox *checkbox = new QCheckBox;
  SetCheckBoxStyle(checkbox);
  return checkbox;
}

void CheckBoxStyleConfigurator::SetCheckBoxStyle(QCheckBox *checkbox) {
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
