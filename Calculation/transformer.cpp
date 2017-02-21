#include "transformer.h"

#include <QString>

Transformer::Transformer()
    : comma_and_dot_(false),
      space_with_comma(false),
      space_with_dot_(false),
      space_(false),
      comma_(false),
      two_commas_(false) {}

double Transformer::TransformString(QString string) {
  Analyze(string);
  Transform(string);
  return string.toDouble();
}

void Transformer::Analyze(const QString &string) {
  comma_and_dot_ = Contains(string, ',', '.');
  space_with_comma = Contains(string, ' ', ',');
  space_with_dot_ = Contains(string, ' ', '.');
  space_ = Contains(string, ' ');
  comma_ = Contains(string, ',');
  two_commas_ = string.count(',') == 2;
}

void Transformer::Transform(QString &string) const {
  if (comma_and_dot_) {
    string.remove(',');
  } else if (space_with_comma) {
    string.remove(' ');
    string.replace(',', '.');
  } else if (space_with_dot_) {
    string.remove(' ');
  } else if (space_) {
    string.remove(' ');
  } else if (two_commas_) {
    DeleteCommas(string);
  } else if (comma_) {
    string.replace(',', '.');
  }
}

bool Transformer::Contains(const QString &string, const char symbol_one,
                           const char symbol_two) const {
  return string.contains(symbol_one) && string.contains(symbol_two);
}

bool Transformer::Contains(const QString &string, const char symbol) const {
  return string.contains(symbol);
}

void Transformer::DeleteCommas(QString &string) const {
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
}
