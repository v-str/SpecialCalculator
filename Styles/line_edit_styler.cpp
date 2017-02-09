#include "line_edit_styler.h"

#include <QLineEdit>

void LineEditStyler::SetLine(QLineEdit *line_edit, int style) {
  switch (style) {
    case 0:
      SetStyleSheet(line_edit, "green", "black");
      break;
    case 1:
      SetStyleSheet(line_edit, "black", "#606060", "normal");
      break;
    case 2:
      SetStyleSheet(line_edit, "#000099", "white");
      break;
  }
}

void LineEditStyler::SetStyleSheet(QLineEdit *line_edit, const QString &color,
                                   const QString &background,
                                   const QString &font_weight) {
  QString style_sheet =
      "QLineEdit {"
      "border: 2px solid %1;"
      "border-radius: 7px;"
      "background: %2;"
      "selection-background-color: #40494D;"
      "color: %3;"
      "font-weight: %4;"
      "}";

  line_edit->setStyleSheet(
      style_sheet.arg(color, background, color, font_weight));
}
