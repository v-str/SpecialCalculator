#ifndef TRANSFORMER_H
#define TRANSFORMER_H

class QString;

class Transformer {
 public:
  static double TransformString(const QString &string);

 private:
  static void Analyze(const QString &string);
  static void Transform(QString &string);

  static bool comma_and_dot_;
  static bool space_with_comma;
  static bool space_with_dot_;
  static bool space_;
  static bool comma_;
};

#endif  // TRANSFORMER_H
