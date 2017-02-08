#include "lcd_styler.h"

#include <QString>

void LCDStyler::SetLCDNumber(QLCDNumber *lcd, config::Theme theme) {
  SetLCDFeature(lcd, true, QLCDNumber::Flat, QFrame::NoFrame);
  SetLCDStyle(lcd, theme);
}

void LCDStyler::SetLCDFeature(QLCDNumber *lcd, bool auto_fill_background,
                                   QLCDNumber::SegmentStyle segment_style,
                                   QFrame::Shape frame_shape) {
  lcd->setAutoFillBackground(auto_fill_background);
  lcd->setSegmentStyle(segment_style);
  lcd->setFrameStyle(frame_shape);
}

void LCDStyler::SetLCDStyle(QLCDNumber *lcd, config::Theme theme) {
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

void LCDStyler::SetLCDStyleSheet(QLCDNumber *lcd,
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
