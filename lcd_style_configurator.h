#ifndef LCD_STYLE_CONFIGURATOR_H
#define LCD_STYLE_CONFIGURATOR_H

class QLCDNumber;

class LcdStyleConfigurator {
 public:
  void SetLCDNumber(QLCDNumber* lcd);

 private:
  void SetStyleForLCD(QLCDNumber* lcd);
};

#endif  // LCD_STYLE_CONFIGURATOR_H
