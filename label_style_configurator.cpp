#include "label_style_configurator.h"

#include <QFont>
#include <QLabel>
#include <QString>

QLabel *LabelStyleConfigurator::GetLabel(const QString &text_label, int label_font) {
  QLabel *label = new QLabel;
  SetLabel(label, text_label, label_font);
  return label;
}

void LabelStyleConfigurator::SetLabel(QLabel *label, const QString text_of_label,
                                int label_font) {
  label->setText("<font color='green'>" + text_of_label + "</font>");
  label->setFont(GetFont(label_font));
}

QFont LabelStyleConfigurator::GetFont(int point_size) {
  QFont font;
  font.setPointSize(point_size);

  return font;
}
