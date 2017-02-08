#ifndef LINE_EDIT_STYLER_H
#define LINE_EDIT_STYLER_H

#include <QString>

class QLineEdit;

class LineEditStyler {
 public:
  static void SetLine(QLineEdit *line_edit, int style);

 private:
  static void StaticSetLineStyleSheet(QLineEdit *line_edit,
                                      const QString &color,
                                      const QString &background,
                                      const QString &font_weight = "bold");
};

#endif  // LINE_EDIT_STYLER_H
