#ifndef LINE_EDIT_STYLE_CONFIG_H
#define LINE_EDIT_STYLE_CONFIG_H

#include <QString>

#include "theme_configuration.h"

class QLineEdit;

class LineEditStyleConfig {
 public:
  void SetCoefficientLine(QLineEdit *line_edit, config::Theme theme);
  void SetValueLine(QLineEdit *line_edit, config::Theme theme);

 private:
  void SetLineFeature(QLineEdit *line_edit, bool disable_status, int w, int h);

  void SetLineEditStyle(QLineEdit *line_edit, config::Theme theme);

  void SetLineStyleSheet(QLineEdit *line_edit, const QString &border_color,
                         const QString &background,
                         const QString &selection_color,
                         const QString &text_color, const QString &font_weight);
};

#endif  // LINE_EDIT_STYLE_CONFIG_H
