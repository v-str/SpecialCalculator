#include "transformer.h"

#include <QString>

double Transformer::modyfied_value_ = 0.0;

void Transformer::TransformString(QString &value) {
  value.remove(' ');
  modyfied_value_ = value.toDouble();
}

double Transformer::GetModyfiedString() { return modyfied_value_; }
