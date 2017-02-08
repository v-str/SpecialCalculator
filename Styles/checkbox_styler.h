#ifndef CHECKBOXSTYLER_H
#define CHECKBOXSTYLER_H

#include "theme_configuration.h"

class QCheckBox;

class CheckBoxStyler {
 public:
  static void SetCheckBox(QCheckBox* checkbox, config::Theme theme);
};

#endif  // CHECKBOXSTYLER_H
