#ifndef LABEL_STYLER_H
#define LABEL_STYLER_H

class QLabel;
class QString;
class QFont;

class LabelStyler {
 public:
  static void SetLabel(QLabel* label, int theme);

 private:
  static void SetStyleSheet(QLabel* label,
                                       const QString& text_of_label,
                                       const QString& text_color,
                                       const QString& background_format,
                                       const QString& background);
};

#endif  // LABEL_STYLER_H
