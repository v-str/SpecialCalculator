#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "label_syler.h"

#include <QWidget>

class QLineEdit;
class QLCDNumber;
class QClipboard;
class QHBoxLayout;
class QCheckBox;
class QGridLayout;

class Calculator : public QWidget {
  Q_OBJECT
 public:
  explicit Calculator(QWidget* parent = nullptr);

 public slots:
  void CalculateResult(const QString& result);

 signals:
  void CompletedDoubleValue(double complete_value);
  void CompleteQStringValue(const QString& complete_value);

 private:
  enum AppTheme { kProgrammer, kMoto, kOffice };

  void SetMainWindow(QGridLayout* layout);

  QCheckBox* GetCheckBox();

  void SetCoefficientLine(QLineEdit* coefficient_line);
  void SetLineEditStyle(QLineEdit* line);
  void SetValueLine(QLineEdit* value_line);
  void SetPaletteForLCD(QLCDNumber* lcd);
  void SetLCDNumber(QLCDNumber* lcd);
  void SetResultLine(QLineEdit* result_line);

  void SetCheckBoxStyle(QCheckBox* checkbox);
  void SetHorizontalLayout(QHBoxLayout* layout, QLabel* label,
                           QCheckBox* checkbox, QLineEdit* line_edit);
  void SetGridLayout(QGridLayout* grid_layout, QHBoxLayout* layout,
                     QLineEdit* line_edit, QLabel* label, QLCDNumber* lcd);

  LabelStyler label_styler_;

  QClipboard* clipboard_ = nullptr;
  QLineEdit* coefficient_line_ = nullptr;
  QLineEdit* value_line_ = nullptr;
  QLCDNumber* lcd_ = nullptr;

  double complete_value_ = 0.0;
};

#endif  // CALCULATOR_H
