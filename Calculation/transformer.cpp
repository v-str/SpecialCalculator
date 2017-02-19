#include "transformer.h"

#include <QDebug>
#include <QString>

bool Transformer::comma_and_dot_ = false;
bool Transformer::space_with_comma = false;
bool Transformer::space_with_dot_ = false;
bool Transformer::space_ = false;
bool Transformer::comma_ = false;
int Transformer::two_commas_ = 0;

double Transformer::TransformString(QString string) {
  Analyze(string);
  Transform(string);
  return string.toDouble();
}

void Transformer::Analyze(const QString &string) {
  comma_and_dot_ = string.contains(',') && string.contains('.');
  space_with_comma = string.contains(' ') && string.contains(',');
  space_with_dot_ = string.contains(' ') && string.contains('.');
  space_ = string.contains(' ');
  comma_ = string.contains(',');
  two_commas_ = string.count(',');
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
  } else if (comma_ && two_commas_ == 2) {
    int index = 0;
    for (int i = 0; i <= string.length(); ++i) {
      if (string[i] == ',') {
        string.remove(i, 1);
        index = i;
        break;
      }
    }
    for (int i = index; i <= string.length(); ++i) {
      if (string[i] == ',') {
        string.replace(',', '.');
      }
    }
  } else if (comma_) {
    string.replace(',', '.');
  }
}
