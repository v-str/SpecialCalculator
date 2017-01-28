#ifndef LINESTYLER_H
#define LINESTYLER_H

class QLineEdit;

class LineStyler {
 public:
  void SetCoefficientLine(QLineEdit* coefficient_line);
  void SetValueLine(QLineEdit* value_line);

 private:
  void SetLineEditStyle(QLineEdit* line);
};

#endif  // LINESTYLER_H
