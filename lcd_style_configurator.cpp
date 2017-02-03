#include "lcd_style_configurator.h"

#include <QLCDNumber>
#include <QPalette>

void LcdStyleConfigurator::SetLCDNumber(QLCDNumber *lcd) {
  lcd->setAutoFillBackground(true);
  lcd->setSegmentStyle(QLCDNumber::Flat);
  lcd->setFrameStyle(QFrame::NoFrame);

  SetStyleForLCD(lcd);
}

void LcdStyleConfigurator::SetStyleForLCD(QLCDNumber *lcd) {
  lcd->setStyleSheet(
      "QLCDNumber {"
      "border: 1px solid green;"
      "border-radius: 7px;"
      "background: black;"
      "color: green;"
      "}");
}
