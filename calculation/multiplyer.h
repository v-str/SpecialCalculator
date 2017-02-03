#ifndef MULTIPLYER_H
#define MULTIPLYER_H

class QString;

class Multiplyer {
 public:
  Multiplyer();

  void SetCoefficient(double coefficient);
  void SetNumber(const QString &value_string);

  QString GetCompleteStringValue();
  double GetCompleteDoubleValue();

 private:
  void Myltiply();

  double multiply_coefficient_;
  double number_;
};

#endif  // MULTIPLYER_H
