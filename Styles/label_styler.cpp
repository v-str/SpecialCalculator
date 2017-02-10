#include "label_styler.h"

#include <QLabel>
#include <QString>

void LabelStyler::SetLabel(QLabel *label, int style) {
  QString label_text = label->text();
  QString background_format = "color";
  QString image = "";

  if (label_text == "Number:") {
    background_format = "image";
    image = "url(:/motogp_logo.jpg)";
  } else if (label_text == "Result:") {
    background_format = "image";
    image = "url(:/moto.jpg)";
  }

  switch (style) {
    case 0:
      SetStyleSheet(label, label_text, "green", background_format, "black");
      break;
    case 1:
      SetStyleSheet(label, label_text, "#CC6600", background_format, "#404040");
      break;
    case 2:
      SetStyleSheet(label, "", "white", background_format, image);
      break;
  }
}

void LabelStyler::SetStyleSheet(QLabel *label, const QString &text_of_label,
                                const QString &text_color,
                                const QString &background_format,
                                const QString &background) {
  label->setText(text_of_label);

  QString temporary_background_format = "background-color: ";

  if (background_format == "image") {
    temporary_background_format = "background-image: ";
  }

  QString style_sheet =
      "QLabel {"
      "color: %1;"
      "%2%3;"
      "}";

  label->setStyleSheet(
      style_sheet.arg(text_color, temporary_background_format, background));
}
