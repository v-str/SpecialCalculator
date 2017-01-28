#include "label_syler.h"

#include <QFont>
#include <QLabel>
#include <QString>

QLabel *LabelStyler::GetLabel(const QString &text_label, int label_font) {
  QLabel *label = new QLabel;
  SetLabel(label, text_label, label_font);
  return label;
}

void LabelStyler::SetLabel(QLabel *label, const QString text_of_label,
                                int label_font) {
  label->setText("<font color='green'>" + text_of_label + "</font>");
  label->setFont(GetFont(label_font));
}

QFont LabelStyler::GetFont(int point_size) {
  QFont font;
  font.setPointSize(point_size);

  return font;
}
