#include "lcd_style_config.h"

#include <QLCDNumber>
#include <QString>

void LCDStyleConfig::SetLCDNumber(QLCDNumber *lcd, config::Theme theme) {
  lcd->setAutoFillBackground(true);
  lcd->setSegmentStyle(QLCDNumber::Flat);
  lcd->setFrameStyle(QFrame::NoFrame);

  SetLCDStyle(lcd, theme);
}

void LCDStyleConfig::SetLCDStyle(QLCDNumber *lcd, config::Theme theme) {
  switch (theme) {
    case config::kProgrammer:
      SetLCDStyleSheet(lcd, "green", "black", "green");
      break;
    case config::kOffice:
      SetLCDStyleSheet(lcd, "black", "#606060", "black");
      break;
    case config::kMoto:
      SetLCDStyleSheet(lcd, "#000099", "white", "black");
      break;
  }
}

void LCDStyleConfig::SetLCDStyleSheet(QLCDNumber *lcd,
                                      const QString &border_color,
                                      const QString &background,
                                      const QString &value_color) {
  lcd->setStyleSheet(
      "QLCDNumber {"
      "border: 2px solid " +
      border_color + ";" + "border-radius: 7px;" + "background: " + background +
      ";" + "color: " + value_color + ";}");
}
