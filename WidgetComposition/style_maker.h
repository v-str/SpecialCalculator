#ifndef STYLEMAKER_H
#define STYLEMAKER_H

#include <memory>

#include "former.h"

class StyleMaker {
  typedef unsigned int Style;

 public:
  StyleMaker(Former *former);

  void SetStyle(Style style = 0);

 private:
  void SetLabel(Style style);
  void SetCheckBox(Style style);
  void SetLineEdit(Style style);
  void SetLCD(Style style);

  Former *former_ = nullptr;
};

#endif  // STYLEMAKER_H
