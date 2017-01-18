#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QLCDNumber>
#include <QLineEdit>
#include <QTextEdit>
#include <QWidget>

class Calculator : public QWidget {
  Q_OBJECT
 public:
  explicit Calculator(QWidget* parent = 0);

 public slots:
  void GetResult(QString result);
  void DisplayResult(double result);

 signals:
  void CompletedDoubleValue(double complete_value);
  void CompleteQStringValue(const QString& complete_value);

 private:
  std::string GetString(double value);

  QLCDNumber* lcd_;
  QLineEdit* coefficient_line_;
  QLineEdit* value_line_;
  QLineEdit* result_line_;

  double complete_double_value_;
};

#endif  // CALCULATOR_H
