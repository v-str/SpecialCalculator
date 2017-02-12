#ifndef FORMER_H
#define FORMER_H

#include <QCheckBox>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>

#include "proportion.h"

#include <QRadioButton>

class Former {
 public:
  Former();
  ~Former();

  Former(const Former& former) = delete;
  Former& operator=(const Former& former) = delete;

  QLabel* CoefficientLabel() const;
  QLabel* NumberLabel() const;
  QLabel* ResultLabel() const;

  QLineEdit* CoefficientLine() const;
  QLineEdit* EditLine() const;

  QCheckBox* StateCheckBox() const;

  QLCDNumber* LCDNumber() const;

  QGridLayout* GridLayout() const;

  QRadioButton* Button1() const;
  QRadioButton* Button2() const;
  QRadioButton* Button3() const;

 private:
  QLabel* number_label_ = nullptr;
  QLabel* result_label_ = nullptr;

  QLineEdit* coefficient_line_ = nullptr;
  QLineEdit* edit_line_ = nullptr;

  QCheckBox* state_checkbox_ = nullptr;

  QLCDNumber* lcd_ = nullptr;

  Proportion* propotion_ = nullptr;

  QRadioButton* programming_button1_ = nullptr;
  QRadioButton* office_button2_ = nullptr;
  QRadioButton* moto_button3_ = nullptr;
};

#endif  // FORMER_H
