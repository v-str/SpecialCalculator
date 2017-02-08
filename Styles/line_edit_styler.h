#ifndef LINE_EDIT_STYLER_H
#define LINE_EDIT_STYLER_H

#include <QString>

#include "theme_configuration.h"

class QLineEdit;

class LineEditStyler {
 public:
  void SetCoefficientLine(QLineEdit *line_edit, config::Theme theme);
  void SetValueLine(QLineEdit *line_edit, config::Theme theme);

 private:
  void SetLineFeature(QLineEdit *line_edit, bool disable_state, int w, int h);

  void SetLineEditStyle(QLineEdit *line_edit, config::Theme theme);

  void SetLineStyleSheet(QLineEdit *line_edit, const QString &color,
                         const QString &background,
                         const QString &font_weight = "bold");
};

#endif  // LINE_EDIT_STYLER_H
