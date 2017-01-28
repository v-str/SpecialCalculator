#ifndef LABEL_STYLER_H
#define LABEL_STYLER_H

class QString;
class QLabel;
class QFont;

class LabelStyler {
 public:
  QLabel* GetLabel(const QString& text_label, int label_font = 10);

 private:
  void SetLabel(QLabel* label, const QString text_of_label,
                int label_font = 10);

  QFont GetFont(int point_size);
};

#endif  // LABEL_STYLER_H
