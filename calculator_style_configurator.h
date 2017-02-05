#ifndef CALCULATOR_STYLE_CONFIGURATOR_H
#define CALCULATOR_STYLE_CONFIGURATOR_H

#include <QAction>
#include <QCheckBox>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

class CaclulatorStyleConfigurator {
 public:
  enum AppTheme { kProgrammer, kMoto, kOffice };

  CaclulatorStyleConfigurator();

  void SetStyle(AppTheme theme);

  QLineEdit *GetValueLine();
  QLineEdit *GetCoefficientLine();
  QLCDNumber *GetLCDNumber();
  QCheckBox *GetCoefficientCheckBox();
  QGridLayout *GetLayout();

 private:
  void SetCoefficientLine(QLineEdit *line, AppTheme theme = kProgrammer);
  void SetValueLine(QLineEdit *line, AppTheme theme = kProgrammer);
  void SetLineEditStyle(QLineEdit *line, AppTheme theme = kProgrammer);
  void SetLCDNumber(QLCDNumber *lcd, AppTheme theme = kProgrammer);
  void SetLCDStyle(QLCDNumber *lcd, AppTheme theme = kProgrammer);
  void SetCoefficientLabel(QLabel *label, const QString &text_of_label,
                int label_size = 10, AppTheme theme = kProgrammer);
  void SetNumberLabel(QLabel *label, const QString &text_of_label,
                int label_size = 10, AppTheme theme = kProgrammer);
  void SetResultLabel(QLabel *label, const QString &text_of_label,
                int label_size = 10, AppTheme theme = kProgrammer);
  void SetCheckBox(QCheckBox *checkbox, AppTheme theme = kProgrammer);
  void SetGridLayout(QGridLayout *grid_layout, QLineEdit *line_edit,
                     QLabel *number_label, QLabel *result_label,
                     QLCDNumber *lcd);
  void SetHorizontalLayout(QHBoxLayout *layout, QLabel *label,
                           QCheckBox *checkbox, QLineEdit *line_edit);

  QLineEdit *coefficient_line_ = nullptr;
  QLineEdit *value_line_ = nullptr;
  QLCDNumber *lcd_ = nullptr;
  QLabel *coefficient_label_ = nullptr;
  QLabel *number_label_ = nullptr;

  QLabel *result_label_ = nullptr;
  QFont GetFont(int point_size);
  QCheckBox *coefficient_checkbox_ = nullptr;
  QGridLayout *grid_layout_ = nullptr;
  QHBoxLayout *horizontal_layout_ = nullptr;
};

#endif  // CALCULATOR_STYLE_CONFIGURATOR_H
