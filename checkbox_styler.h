#ifndef CHECKBOXSTYLER_H
#define CHECKBOXSTYLER_H

class QCheckBox;

class CheckBoxStyler {
 public:
  QCheckBox* GetCheckBox();

 private:
  void SetCheckBoxStyle(QCheckBox* checkbox);
};

#endif  // CHECKBOXSTYLER_H
