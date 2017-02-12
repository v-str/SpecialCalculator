#ifndef RADIOBUTTON_STYLER_H
#define RADIOBUTTON_STYLER_H

#include <QString>

class QRadioButton;

class RadiobuttonStyler {
 public:
  static void SetStyle(QRadioButton *button, int style);

  static void SetStyleSheet(QRadioButton *button, const QString &border_color,
                            const QString &unchecked_color,
                            const QString &checked_color);
};

#endif  // RADIOBUTTON_STYLER_H
