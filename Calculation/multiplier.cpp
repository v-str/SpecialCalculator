#include "multiplier.h"
#include "transformer.h"

#include <cmath>

#include <QString>

Multiplier::Multiplier() : multiply_coefficient_(0.0), number_(0.0) {}

void Multiplier::SetMultiplyCoefficient(double multiply_coefficient) {
  multiply_coefficient_ = multiply_coefficient;
}

void Multiplier::SetNumber(const QString &value_string) {
  number_ = Transformer::TransformString(value_string);
  Myltiply();
}

QString Multiplier::GetCompleteStringValue() {
  return QString::number(number_, 'g', 10);
}

double Multiplier::GetCompleteDoubleValue() const { return number_; }

void Multiplier::Myltiply() {
  number_ *= multiply_coefficient_;
  number_ = round(number_ * 100) / 100;
}
