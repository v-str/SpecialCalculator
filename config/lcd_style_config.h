#ifndef LCDSTYLECONFIG_H
#define LCDSTYLECONFIG_H

#include "theme_configuration.h"

class QLCDNumber;
class QString;

class LCDStyleConfig {
 public:
  void SetLCDNumber(QLCDNumber *lcd, config::Theme theme);

 private:
  void SetLCDStyle(QLCDNumber *lcd, config::Theme theme);
  void SetLCDStyleSheet(QLCDNumber *lcd, const QString &border_color,
                        const QString &background, const QString &value_color);
};

#endif  // LCDSTYLECONFIG_H
