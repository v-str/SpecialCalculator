#include "line_edit_style_config.h"

#include <QLineEdit>

void LineEditStyleConfig::SetCoefficientLine(QLineEdit *line_edit,
                                             config::Theme theme) {
  line_edit->setDisabled(true);
  line_edit->setAlignment(Qt::AlignRight);
  line_edit->setMaximumSize(75, 25);

  SetLineEditStyle(line_edit, theme);
}

void LineEditStyleConfig::SetValueLine(QLineEdit *line_edit,
                                       config::Theme theme) {
  line_edit->setAlignment(Qt::AlignRight);
  SetLineEditStyle(line_edit, theme);
}

void LineEditStyleConfig::SetLineEditStyle(QLineEdit *line_edit,
                                           config::Theme theme) {
  if (theme == config::kProgrammer) {
    SetLineStyleSheet(line_edit, "green", "black", "#40494D", "green", "bold");
  } else if (theme == config::kOffice) {
    SetLineStyleSheet(line_edit, "black", "#606060", "#40494D", "black",
                      "normal");
  } else if (theme == config::kMoto) {
    SetLineStyleSheet(line_edit, "#000099", "white", "#40494D", "black",
                      "bold");
  }
}

void LineEditStyleConfig::SetLineStyleSheet(QLineEdit *line_edit,
                                            const QString &border_color,
                                            const QString &background,
                                            const QString &selection_color,
                                            const QString &text_color,
                                            const QString &font_weight) {
  QString style_sheet =
      "QLineEdit {"
      "border: 2px solid %1;"
      "border-radius: 7px;"
      "background: %2;"
      "selection-background-color: %3;"
      "color: %4;"
      "font-weight: %5;}";

  line_edit->setStyleSheet(style_sheet.arg(
      border_color, background, selection_color, text_color, font_weight));
}
