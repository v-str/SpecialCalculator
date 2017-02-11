#include "checkbox_styler.h"

#include <QCheckBox>

void CheckBoxStyler::SetCheckBox(QCheckBox *checkbox, int style) {
  switch (style) {
    case 0:
      SetStyleSheet(checkbox, "#084913", "black", "#00FF00");
      break;
    case 1:
      SetStyleSheet(checkbox, "black", "#606060", "#CC6600");
      break;
    case 2:
      SetStyleSheet(checkbox, "#000099", "white", "#0080FF");
      break;
  }
}

void CheckBoxStyler::SetStyleSheet(QCheckBox *checkbox,
                                   const QString &border_color,
                                   const QString &unchecked_color,
                                   const QString &checked_color) {
  QString style_sheet =
      "QCheckBox::indicator {"
      "width: 15px;"
      "height: 15px;"
      "}"
      "QCheckBox::indicator:unchecked {"
      "border: 2px solid %1;"
      "border-radius: 5px;"
      "background-color: %2;"
      "}"
      "QCheckBox::indicator:checked {"
      "border: 2px solid %3;"
      "border-radius: 5px;"
      "background-color: %4;"
      "}";

  checkbox->setStyleSheet(style_sheet.arg(border_color, unchecked_color,
                                          border_color, checked_color));
}
