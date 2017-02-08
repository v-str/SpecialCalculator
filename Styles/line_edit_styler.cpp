#include "line_edit_styler.h"

#include <QLineEdit>

void LineEditStyler::SetLine(QLineEdit *line_edit, int style) {
  switch (style) {
    case 0:
      StaticSetLineStyleSheet(line_edit, "green", "black");
      break;
    case 1:
      StaticSetLineStyleSheet(line_edit, "black", "#606060", "normal");
      break;
    case 2:
      StaticSetLineStyleSheet(line_edit, "#000099", "white");
      break;
  }
}

void LineEditStyler::StaticSetLineStyleSheet(QLineEdit *line_edit,
                                             const QString &color,
                                             const QString &background,
                                             const QString &font_weight) {
  QString style_sheet =
      "QLineEdit {"
      "border: 2px solid %1;"
      "border-radius: 7px;"
      "background: %2;"
      "selection-background-color: #40494D;"
      "color: %4;"
      "font-weight: %5;}";

  line_edit->setStyleSheet(
      style_sheet.arg(color, background, color, font_weight));
}
