#include "transformer.h"

#include <QString>

bool Transformer::comma_and_dot_ = false;
bool Transformer::space_with_comma = false;
bool Transformer::space_with_dot_ = false;
bool Transformer::space_ = false;
bool Transformer::comma_ = false;

double Transformer::TransformString(const QString &string) {
  QString modyfied_string = string;
  Analyze(modyfied_string);
  Transform(modyfied_string);
  return modyfied_string.toDouble();
}

void Transformer::Analyze(const QString &string) {
  comma_and_dot_ = (string.contains(',') && string.contains('.'));
  space_with_comma = (string.contains(' ') && string.contains(','));
  space_with_dot_ = (string.contains(' ') && string.contains('.'));
  space_ = string.contains(' ');
  comma_ = string.contains(',');
}

void Transformer::Transform(QString &string) {
  if (comma_and_dot_) {
    string.remove(',');
  } else if (space_with_comma) {
    string.remove(' ');
    string.replace(',', '.');
  } else if (space_with_dot_) {
    string.remove(' ');
  } else if (space_) {
    string.remove(' ');
  } else if (comma_) {
    string.replace(',', '.');
  }
}
