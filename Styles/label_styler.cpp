#include "label_styler.h"

#include <QFont>
#include <QLabel>
#include <QString>

LabelStyler::LabelStyler() : font_(new QFont) {}

void LabelStyler::SetLabel(QLabel *label, const QString &text, int size,
                           config::Theme theme) {
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
    case config::kProgrammer:
      SetLabelStyleSheet(label, text, "green", background, "black");
      break;
    case config::kOffice:
      SetLabelStyleSheet(label, text, "#CC6600", background, "#404040");
      break;
    case config::kMoto:
      SetLabelStyleSheet(label, "", "white", background, image);
      break;
  }
  label->setFont(Font(size));
}

void LabelStyler::SetLabelStyleSheet(QLabel *label,
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

QFont LabelStyler::Font(int size) {
  font_->setPointSize(size);
  return *font_;
}
