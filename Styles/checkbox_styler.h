#ifndef CHECKBOXSTYLER_H
#define CHECKBOXSTYLER_H

#include <QString>

class QCheckBox;

class CheckBoxStyler {
 public:
  static void SetCheckBox(QCheckBox* checkbox, int style);

 private:
  static void SetStyleSheet(QCheckBox* checkbox, const QString border_color,
                            const QString unchecked_color,
                            const QString checked_color);
};

#endif  // CHECKBOXSTYLER_H
