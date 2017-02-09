#ifndef LCD_STYLER_H
#define LCD_STYLER_H

#include <QLCDNumber>

class QString;

class LCDStyler {
 public:
  static void SetLCD(QLCDNumber *lcd, int style);

 private:
  static void SetStyleSheet(QLCDNumber *lcd,
                                     const QString &border_color,
                                     const QString &background,
                                     const QString &value_color);
};

#endif  // LCD_STYLER_H
