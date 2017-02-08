#ifndef LABEL_STYLER_H
#define LABEL_STYLER_H

#include "theme_configuration.h"

class QLabel;
class QString;
class QFont;

class LabelStyler {
 public:
  LabelStyler();

  void SetLabel(QLabel* label, const QString& text, int size,
                config::Theme theme);

  void SetLabelStyleSheet(QLabel* label, const QString& text_of_label,
                          const QString& text_color,
                          const QString& background_format,
                          const QString& background);

  QFont Font(int size);

 private:
  QFont* font_ = nullptr;
};

#endif  // LABEL_STYLER_H
