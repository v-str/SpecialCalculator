#ifndef LCD_STYLER_H
#define LCD_STYLER_H

#include <QLCDNumber>

#include "theme_configuration.h"

class QString;

class LCDStyler {
 public:
  void SetLCDNumber(QLCDNumber *lcd, config::Theme theme);

 private:
  void SetLCDFeature(QLCDNumber *lcd, bool auto_fill_background,
                     QLCDNumber::SegmentStyle segment_style,
                     QLCDNumber::Shape frame_shape);
  void SetLCDStyle(QLCDNumber *lcd, config::Theme theme);
  void SetLCDStyleSheet(QLCDNumber *lcd, const QString &border_color,
                        const QString &background, const QString &value_color);
};

#endif  // LCD_STYLER_H
