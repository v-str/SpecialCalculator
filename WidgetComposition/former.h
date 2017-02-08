#ifndef FORMER_H
#define FORMER_H

#include <QCheckBox>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>

class Former {
 public:
  Former();
  ~Former();

  QLabel* CoefficientLabel() const;
  QLabel* NumberLabel() const;
  QLabel* ResultLabel() const;

  QLineEdit* CoefficientLine() const;
  QLineEdit* EditLine() const;

  QCheckBox* StateCheckBox() const;
  QCheckBox* ProgrammerCheckBox() const;
  QCheckBox* OfficeCheckBox() const;
  QCheckBox* MotoCheckBox() const;

  QLCDNumber* LCDNumber() const;

  QGridLayout* GridLayout() const;

 private:
  void SetWidgetFont();
  void SetLayout();
  void SetWidgetAppearance();

  template <typename Widget>
  void SetFont(Widget* widget, int font_size);

  const QFont& Font(int size);

  QLabel* number_label_ = nullptr;
  QLabel* result_label_ = nullptr;

  QLineEdit* coefficient_line_ = nullptr;
  QLineEdit* edit_line_ = nullptr;

  QCheckBox* state_checkbox_ = nullptr;
  QCheckBox* programmer_style_checkbox_ = nullptr;
  QCheckBox* office_style_checkbox_ = nullptr;
  QCheckBox* moto_style_checkbox_ = nullptr;

  QLCDNumber* lcd_ = nullptr;

  QHBoxLayout* radio_layout_ = nullptr;
  QHBoxLayout* horizontal_layout_ = nullptr;
  QGridLayout* grid_layout_ = nullptr;

  QFont* font_ = nullptr;
};

#endif  // FORMER_H
