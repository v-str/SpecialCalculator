#ifndef LABEL_STYLER_H
#define LABEL_STYLER_H

class QLabel;
class QString;

class LabelStyler {
 public:
  static void SetLabel(QLabel* label, int style);

 private:
  static void SetStyleSheet(QLabel* label, const QString& text_of_label,
                            const QString& text_color,
                            const QString& background_variant,
                            const QString& background);
};

#endif  // LABEL_STYLER_H
