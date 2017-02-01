#ifndef TRANSFORMER_H
#define TRANSFORMER_H

class QString;

class Transformer {
 public:
  static void TransformString(QString &value);
  static double GetTransformedValue();

 private:
  static double modyfied_value_;
};

#endif  // TRANSFORMER_H
