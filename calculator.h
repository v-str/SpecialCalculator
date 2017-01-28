#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "checkbox_styler.h"
#include "common_layout.h"
#include "label_styler.h"
#include "lcd_styler.h"
#include "line_styler.h"

#include <QWidget>

class QClipboard;

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

  LabelStyler label_styler_;
  CheckBoxStyler checkbox_styler_;
  LineStyler line_styler_;
  LcdStyler lcd_styler_;
  CommonLayout layout_;

  QClipboard* clipboard_ = nullptr;
  QLineEdit* coefficient_line_ = nullptr;
  QLineEdit* value_line_ = nullptr;
  QLCDNumber* lcd_ = nullptr;

  double complete_value_ = 0.0;
};

#endif  // CALCULATOR_H
