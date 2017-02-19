#ifndef MULTIPLIER_H
#define MULTIPLIER_H

#include "transformer.h"

class QString;

class Multiplier {
 public:
  Multiplier();

  void SetMultiplyCoefficient(double multiply_coefficient);
  void SetNumber(const QString &value_string);

  QString GetCompleteStringValue();
  double GetCompleteDoubleValue() const;

 private:
  void Myltiply();

  Transformer transformer_;

  double multiply_coefficient_;
  double number_;
};

#endif  // MULTIPLIER_H
