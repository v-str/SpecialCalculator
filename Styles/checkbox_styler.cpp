#include "checkbox_styler.h"

#include <QCheckBox>

void CheckBoxStyler::SetCheckBox(QCheckBox *checkbox, int style) {
  switch (style) {
    case 0:
      checkbox->setStyleSheet(
          "QCheckBox::indicator {"
          "width: 15px;"
          "height: 15px;"
          "}"
          "QCheckBox::indicator:unchecked {"
          "border: 2px solid #084913;"
          "border-radius: 5px;"
          "background-color: black;"
          "}"
          "QCheckBox::indicator:checked {"
          "border: 2px solid #084913;"
          "border-radius: 5px;"
          "background-color: #00FF00;"
          "}");
      break;
    case 1:
      checkbox->setStyleSheet(
          "QCheckBox::indicator {"
          "width: 15px;"
          "height: 15px;"
          "}"
          "QCheckBox::indicator:unchecked {"
          "border: 2px solid black;"
          "border-radius: 5px;"
          "background-color: #606060;"
          "}"
          "QCheckBox::indicator:checked {"
          "border: 2px solid black;"
          "border-radius: 5px;"
          "background-color: #CC6600;"
          "}");
      break;
    case 2:
      checkbox->setStyleSheet(
          "QCheckBox::indicator {"
          "width: 17px;"
          "height: 17px;"
          "}"
          "QCheckBox::indicator:unchecked {"
          "border: 2px solid #000099;"
          "border-radius: 5px;"
          "background-color: white;"
          "}"
          "QCheckBox::indicator:checked {"
          "border: 2px solid #000099;"
          "border-radius: 5px;"
          "background-color: #0080FF;"
          "}");
      break;
  }
}
