#ifndef CALCULATOR_STYLER_H
#define CALCULATOR_STYLER_H

class QLineEdit;
class QLCDNumber;

class LabelStyler;
class CheckBoxStyler;
class LineStyler;
class LcdStyler;
class CommonLayout;

class CalculatorStyler {
 public:
  enum AppTheme { kProgrammer, kMoto, kOffice };

  CalculatorStyler();
  ~CalculatorStyler();
  void SetStyle(AppTheme theme);

  QLineEdit *GetCoefficientLine() const;
  QLineEdit *GetValueLine() const;
  QLCDNumber *GetLCD() const;
  CheckBoxStyler *GetCheckBoxStyler() const;

 private:
  QLineEdit *coefficient_line_ = nullptr;
  QLineEdit *value_line_ = nullptr;
  QLCDNumber *lcd_ = nullptr;

  LabelStyler *label_styler_ = nullptr;
  CheckBoxStyler *checkbox_styler_ = nullptr;
  LineStyler *line_styler_ = nullptr;
  LcdStyler *lcd_styler_ = nullptr;
  CommonLayout *layout_ = nullptr;
};

#endif  // CALCULATOR_STYLER_H
