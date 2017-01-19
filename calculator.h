#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QLCDNumber>
#include <QLineEdit>
#include <QTextEdit>
#include <QWidget>

class Calculator : public QWidget {
  Q_OBJECT
 public:
  explicit Calculator(QWidget* parent = nullptr);

 public slots:
  void CalculateResult(const QString& result);
  void DisplayResult(double result);

 signals:
  void CompletedDoubleValue(double complete_value);
  void CompleteQStringValue(const QString& complete_value);

 private:
  void SetCoefficientLine(QLineEdit* coefficient_line);
  void SetPaletteForLineEdit(QLineEdit* line);

  void SetValueLine(QLineEdit* value_line);
  void SetResultLine(QLineEdit* result_line);

  void SetPaletteForLCD(QLCDNumber* lcd);
  void SetLCDNumber(QLCDNumber* lcd);

  QLineEdit* coefficient_line_ = nullptr;
  QLineEdit* value_line_ = nullptr;
  QLCDNumber* lcd_ = nullptr;
  QLineEdit* result_line_ = nullptr;

  double complete_value_ = 0.0;
};

#endif  // CALCULATOR_H
