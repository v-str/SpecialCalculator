#ifndef STYLEMAKER_H
#define STYLEMAKER_H

#include "former.h"

class StyleMaker {
 public:
  using Style = unsigned int;

  explicit StyleMaker(Former *former);

  void SetStyle(Style style = 0);

 private:
  void SetLabel(Style style);
  void SetCheckBox(Style style);
  void SetLineEdit(Style style);
  void SetLCD(Style style);
  void SetRadioButton(Style style);

  Former *former_ = nullptr;
};

#endif  // STYLEMAKER_H
