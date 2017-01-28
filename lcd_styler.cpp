#include "lcd_styler.h"

#include <QLCDNumber>
#include <QPalette>

void LcdStyler::SetLCDNumber(QLCDNumber *lcd) {
  lcd->setAutoFillBackground(true);
  lcd->setSegmentStyle(QLCDNumber::Flat);
  lcd->setFrameStyle(QFrame::NoFrame);

  SetStyleForLCD(lcd);
}

void LcdStyler::SetStyleForLCD(QLCDNumber *lcd) {
  lcd->setStyleSheet(
      "QLCDNumber {"
      "border: 1px solid green;"
      "border-radius: 7px;"
      "background: black;"
      "color: green;"
      "}");
}
