#ifndef LINE_STYLE_CONFIGURATOR_H
#define LINE_STYLE_CONFIGURATOR_H

class QLineEdit;

class LineStyleConfigurator {
 public:
  void SetCoefficientLine(QLineEdit* coefficient_line);
  void SetValueLine(QLineEdit* value_line);

 private:
  void SetLineEditStyle(QLineEdit* line);
};

#endif  // LINE_STYLE_CONFIGURATOR_H
