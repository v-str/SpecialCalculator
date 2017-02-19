#ifndef TRANSFORMER_H
#define TRANSFORMER_H

class QString;

class Transformer {
 public:
  Transformer();

  double TransformString(QString string);

 private:
  void Analyze(const QString &string);
  void Transform(QString &string) const;

  bool Contains(const QString &string, const char symbol_one,
                const char symbol_two);
  bool Contains(const QString &string, const char symbol);

  void DeleteCommas(QString &string) const;

  bool comma_and_dot_;
  bool space_with_comma;
  bool space_with_dot_;
  bool space_;
  bool comma_;
  bool two_commas_;
};

#endif  // TRANSFORMER_H
