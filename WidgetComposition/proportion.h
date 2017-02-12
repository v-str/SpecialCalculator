#ifndef PROPORTION_H
#define PROPORTION_H

#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>

class QCheckBox;
class QLineEdit;
class QLabel;
class QLCDNumber;
class QWidget;

class QRadioButton;

class Proportion {
 public:
  Proportion();
  ~Proportion();

  Proportion(const Proportion& proportion) = delete;

  void SetProportion(QRadioButton* button1, QRadioButton* button2,
                     QRadioButton* button3, QCheckBox* state_checkbox,
                     QLineEdit* coefficient_line, QLabel* number_label,
                     QLineEdit* edit_line, QLabel* result_label,
                     QLCDNumber* lcd);

  QGridLayout* GridLayout();

 private:
  static void SetWidgetAppearance(QLineEdit* coefficient_line,
                                  QLineEdit* edit_line, QLCDNumber* lcd,
                                  QRadioButton* button1);

  void SetHorizontalLayout(QRadioButton* button1, QRadioButton* button2,
                           QRadioButton* button3, QCheckBox* state_checkbox,
                           QLineEdit* coefficient_line);

  void SetGridLayout(QLabel* number_label, QLineEdit* edit_line,
                     QLabel* result_label, QLCDNumber* lcd);

  void SetWidgetFont(QLabel* number_label, QLabel* result_label,
                     QLineEdit* coefficient_line, QLineEdit* edit_line,
                     QLCDNumber* lcd);

  void SetFont(QWidget* widget, int font_size);

  const QFont& Font(int font_size);

  QHBoxLayout* horizontal_layout_ = nullptr;
  QGridLayout* grid_layout_ = nullptr;

  QFont* font_ = nullptr;
};

#endif  // PROPORTION_H
