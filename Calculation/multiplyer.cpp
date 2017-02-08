#include "multiplyer.h"
#include "transformer.h"

#include <cmath>

#include <QString>

Multiplyer::Multiplyer() : multiply_coefficient_(0.0), number_(0.0) {}

void Multiplyer::SetMultiplyCoefficient(double multiply_coefficient) {
  multiply_coefficient_ = multiply_coefficient;
}

void Multiplyer::SetNumber(const QString &value_string) {
  number_ = Transformer::TransformString(value_string);
  Myltiply();
}

QString Multiplyer::GetCompleteStringValue() {
  return QString::number(number_, 'g', 10);
}

double Multiplyer::GetCompleteDoubleValue() { return number_; }

void Multiplyer::Myltiply() {
  number_ *= multiply_coefficient_;
  number_ = round(number_ * 100) / 100;
}
