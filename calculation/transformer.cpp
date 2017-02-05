#include "transformer.h"

#include <QString>

double Transformer::TransformString(const QString &value) {
  QString modyfied_string_value_ = value;
  modyfied_string_value_.remove(' ');
  return modyfied_string_value_.toDouble();
}
