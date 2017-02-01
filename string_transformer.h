#ifndef STRING_TRANSFORMER_H
#define STRING_TRANSFORMER_H

class QString;

class StringTransformer {
 public:
  static void TransformString(QString &value);
  static double GetModyfiedString();

 private:
  static double modyfied_value_;
};

#endif  // STRING_TRANSFORMER_H
