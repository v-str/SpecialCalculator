#ifndef MULTIPLYER_H
#define MULTIPLYER_H

class QString;

class Multiplyer {
 public:
  Multiplyer();

  void SetMultiplyCoefficient(double multiply_coefficient);
  void SetNumber(const QString &value_string);

  QString GetCompleteStringValue();
  double GetCompleteDoubleValue() const;

 private:
  void Myltiply();

  double multiply_coefficient_;
  double number_;
};

#endif  // MULTIPLYER_H
