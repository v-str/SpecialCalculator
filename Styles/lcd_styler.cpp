#include "lcd_styler.h"

#include <QString>

void LCDStyler::SetLCD(QLCDNumber *lcd, int style) {
  switch (style) {
    case 0:
      SetStyleSheet(lcd, "green", "black", "green");
      break;
    case 1:
      SetStyleSheet(lcd, "black", "#606060", "black");
      break;
    case 2:
      SetStyleSheet(lcd, "#000099", "white", "#000099");
      break;
  }
}

void LCDStyler::SetStyleSheet(QLCDNumber *lcd,
                                       const QString &border_color,
                                       const QString &background,
                                       const QString &value_color) {
  QString style_sheet =
      "QLCDNumber {"
      "border: 2px solid %1;"
      "border-radius:7px;"
      "background: %2;"
      "color: %3;"
      "}";

  lcd->setStyleSheet(style_sheet.arg(border_color, background, value_color));
}
