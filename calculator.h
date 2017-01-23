#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

class QLineEdit;
class QFont;
class QLabel;
class QLCDNumber;
class QClipboard;
class QHBoxLayout;

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
  QLabel* GetLabel(const QString& text_label, int label_font = 10);

  void SetCoefficientLine(QLineEdit* coefficient_line);
  void SetPaletteForLineEdit(QLineEdit* line);

  void SetValueLine(QLineEdit* value_line);

  void SetPaletteForLCD(QLCDNumber* lcd);
  void SetLCDNumber(QLCDNumber* lcd);

  void SetResultLine(QLineEdit* result_line);

  void SetLabel(QLabel* label, const QString text_of_label,
                int label_font = 10);
  QFont GetFont(int point_size);

  QClipboard* clipboard_;
  QLineEdit* coefficient_line_ = nullptr;
  QLineEdit* value_line_ = nullptr;
  QLCDNumber* lcd_ = nullptr;

  double complete_value_ = 0.0;
};

#endif  // CALCULATOR_H
