#include "radiobutton_styler.h"

#include <QRadioButton>

void RadiobuttonStyler::SetStyle(QRadioButton *button, int style) {
  switch (style) {
    case 0:
      SetStyleSheet(button, "#084913", "black", "#00FF00");
      break;
    case 1:
      SetStyleSheet(button, "black", "#606060", "#CC6600");
      break;
    case 2:
      SetStyleSheet(button, "#000099", "white", "#0080FF");
      break;
  }
}

void RadiobuttonStyler::SetStyleSheet(QRadioButton *button,
                                      const QString &border_color,
                                      const QString &unchecked_color,
                                      const QString &checked_color) {
  QString style_sheet =
      "QRadioButton::indicator {"
      "width: 14px;"
      "height: 14px; "
      "}"
      "QRadioButton::indicator:unchecked {"
      "border: 2px solid %1;"
      "border-radius: 8px;"
      "background-color: %2;"
      "}"
      "QRadioButton::indicator:checked {"
      "border: 2px solid %3;"
      "border-radius: 8px;"
      "background-color: %4"
      "}";

  button->setStyleSheet(style_sheet.arg(border_color, unchecked_color,
                                        border_color, checked_color));
}
