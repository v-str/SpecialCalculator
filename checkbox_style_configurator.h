#ifndef CHECKBOX_STYLE_CONFIGURATOR_H
#define CHECKBOX_STYLE_CONFIGURATOR_H

class QCheckBox;

class CheckBoxStyleConfigurator {
 public:
  QCheckBox* GetCheckBox();

 private:
  void SetCheckBoxStyle(QCheckBox* checkbox);
};

#endif  // CHECKBOX_STYLE_CONFIGURATOR_H

