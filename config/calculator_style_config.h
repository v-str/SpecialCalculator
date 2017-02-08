#ifndef CALCULATOR_STYLE_CONFIG_H
#define CALCULATOR_STYLE_CONFIG_H

#include <QAction>
#include <QCheckBox>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

#include "lcd_styler.h"

#include "line_edit_style_config.h"

#include "theme_configuration.h"

class CaclulatorStyleConfig {
 public:
  CaclulatorStyleConfig();

  void SetStyle(config::Theme theme = config::kProgrammer);

  QLineEdit *GetValueLine();
  QLineEdit *GetCoefficientLine();
  QLCDNumber *GetLCDNumber();
  QCheckBox *GetCoefficientCheckBox();
  QGridLayout *GetLayout();

 private:
  void SetLabel(QLabel *label, const QString &text_of_label,
                int label_size = 10, config::Theme theme = config::kProgrammer);

  void SetLabelStyleSheet(QLabel *label, const QString &text_of_label,
                          const QString &text_color,
                          const QString &background_format,
                          const QString &background);

  QFont GetFont(int point_size);

  void SetCheckBox(QCheckBox *checkbox, config::Theme theme);

  void SetGridLayout(QGridLayout *grid_layout, QLabel *number_label,
                     QLineEdit *line_edit, QLabel *result_label,
                     QLCDNumber *lcd);

  void SetHorizontalLayout(QHBoxLayout *layout, QLabel *label,
                           QCheckBox *checkbox, QLineEdit *line_edit);

  QLineEdit *coefficient_line_ = nullptr;
  QLineEdit *value_line_ = nullptr;
  QLCDNumber *lcd_ = nullptr;
  QLabel *coefficient_label_ = nullptr;
  QLabel *number_label_ = nullptr;
  QLabel *result_label_ = nullptr;
  QCheckBox *coefficient_checkbox_ = nullptr;
  QGridLayout *grid_layout_ = nullptr;
  QHBoxLayout *horizontal_layout_ = nullptr;

  LineEditStyleConfig *line_edit_styler = nullptr;
  LCDStyler *lcd_styler_ = nullptr;
};

#endif  // CALCULATOR_STYLE_CONFIGUR_H
