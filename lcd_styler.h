#ifndef LCDSTYLER_H
#define LCDSTYLER_H

class QLCDNumber;

class LcdStyler {
 public:
  void SetLCDNumber(QLCDNumber* lcd);

 private:
  void SetPaletteForLCD(QLCDNumber* lcd);
};

#endif  // LCDSTYLER_H
