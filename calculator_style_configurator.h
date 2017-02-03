#ifndef CALCULATOR_STYLE_CONFIGURATOR_H
#define CALCULATOR_STYLE_CONFIGURATOR_H

class QLabel;
class QCheckBox;
class QLineEdit;
class QLCDNumber;
class QGridLayout;

class LabelStyleConfigurator;
class CheckBoxStyleConfigurator;
class LineStyleConfigurator;
class LcdStyleConfigurator;
class CommonLayout;

class CaclulatorStyleConfigurator {
 public:
  enum AppTheme { kProgrammer, kMoto, kOffice };

  CaclulatorStyleConfigurator();

  void SetStyle(AppTheme theme);

  QLineEdit *GetValueLine();

  QLCDNumber *GetLCDNumber();

  QLineEdit *GetCoefficientLine();

  QCheckBox *GetCoefficientCheckBox();

  QGridLayout *GetLayout();

 private:
  QLineEdit *coefficient_line_ = nullptr;
  QLineEdit *value_line_ = nullptr;
  QLCDNumber *lcd_ = nullptr;

  QLabel *coefficient_label_ = nullptr;
  QLabel *result_label_ = nullptr;
  QCheckBox *coefficient_checkbox_ = nullptr;

  LabelStyleConfigurator *label_styler_ = nullptr;
  CheckBoxStyleConfigurator *checkbox_styler_ = nullptr;
  LineStyleConfigurator *line_styler_ = nullptr;
  LcdStyleConfigurator *lcd_styler_ = nullptr;
  CommonLayout *layout_ = nullptr;
};

#endif  // CALCULATOR_STYLE_CONFIGURATOR_H
