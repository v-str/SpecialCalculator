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

/// по мэйну - не выделять в куче QPalette
/// расположить рядом вызовом setPalette()
///
/// занулять к nullptr все указатели
/// не использовать = 0 с указателями
///
/// ссылки в передаче аргументов
///
/// forward declaration для QLCDNumber и QLineEdit
///
/// значение по умолчанию для complete_double_value_
///
/// не указывать в названии поля его тип(double в данном случае)
///
/// переименовать гет
///
/// .h файл соответствующего .cpp файла должен стоять на первом месте всегда
///
/// не включать std::string

