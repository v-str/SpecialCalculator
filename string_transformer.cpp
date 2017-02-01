#include "string_transformer.h"

#include <QString>
#include <algorithm>

double StringTransformer::modyfied_value_ = 0.0;

void StringTransformer::TransformString(QString &value) {
  value.remove(' ');
  modyfied_value_ = value.toDouble();
}

double StringTransformer::GetModyfiedString() { return modyfied_value_; }
