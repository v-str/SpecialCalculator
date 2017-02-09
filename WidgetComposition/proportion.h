#ifndef PROPORTION_H
#define PROPORTION_H

#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>

class QCheckBox;
class QLineEdit;
class QLabel;
class QLCDNumber;

class Proportion {
 public:
  Proportion();
  ~Proportion();

  void SetProportion(QCheckBox* programmer_checkbox, QCheckBox* office_checkbox,
                    QCheckBox* moto_checkbox, QCheckBox* state_checkbox,
                    QLineEdit* coefficient_line, QLabel* number_label,
                    QLineEdit* edit_line, QLabel* result_label,
                    QLCDNumber* lcd);

  QGridLayout* GridLayout();

 private:
  void SetWidgetAppearance(QLineEdit * coefficient_line,
                           QLineEdit * edit_line,
                           QLCDNumber * lcd,
                           QCheckBox * programmer_checkbox);

  void SetHorizontalLayoutProportion(QCheckBox* programmer_checkbox,
                                     QCheckBox* office_checkbox,
                                     QCheckBox* moto_checkbox,
                                     QCheckBox* state_checkbox,
                                     QLineEdit* coefficient_line);

  void SetGridLayoutProportion(QLabel* number_label, QLineEdit* edit_line,
                               QLabel* result_label, QLCDNumber* lcd);

  void SetWidgetFont(QLabel* number_label, QLabel* result_label,
                     QLineEdit* coefficient_line, QLineEdit* edit_line,
                     QLCDNumber* lcd);

  template <typename Widget>
  void SetFont(Widget* widget, int font_size);

  const QFont& Font(int font_size);

  QHBoxLayout* horizontal_layout_ = nullptr;
  QGridLayout* grid_layout_ = nullptr;

  QFont* font_ = nullptr;
};

#endif  // PROPORTION_H
