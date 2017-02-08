#include "label_styler.h"

#include <QFont>
#include <QLabel>
#include <QString>

void LabelStyler::SetLabel(QLabel *label, int theme) {
  QString text = label->text();

  QString background = "color";
  QString image = "url(:/motogp_logo.jpg)";

  if (text == "Coefficient") {
    image = "white";
  } else if (text == "Number:") {
    background = "image";
  } else if (text == "Result:") {
    background = "image";
    image = "url(:/moto.jpg)";
  }

  switch (theme) {
    case 0:
      StaticSetLabelStyleSheet(label, text, "green", background, "black");
      break;
    case 1:
      StaticSetLabelStyleSheet(label, text, "#CC6600", background, "#404040");
      break;
    case 2:
      StaticSetLabelStyleSheet(label, "", "white", background, image);
      break;
  }
}

void LabelStyler::StaticSetLabelStyleSheet(QLabel *label,
                                           const QString &text_of_label,
                                           const QString &text_color,
                                           const QString &background_format,
                                           const QString &background) {
  QString temporary_background_format = "";

  if (background_format == "color") {
    temporary_background_format = "background-color: ";
  } else if (background_format == "image") {
    temporary_background_format = "background-image: ";
  }

  label->setText(text_of_label);
  label->setStyleSheet(
      "QLabel {"
      "color: " +
      text_color + ";" + temporary_background_format + background + ";}");
}
