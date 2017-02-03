#include "line_style_configurator.h"

#include <QLineEdit>

void LineStyleConfigurator::SetCoefficientLine(QLineEdit *coefficient_line) {
  coefficient_line->setDisabled(true);
  coefficient_line->setAlignment(Qt::AlignRight);
  coefficient_line->setText("1.18");
  coefficient_line->setMaximumSize(75, 25);
  SetLineEditStyle(coefficient_line);
}

void LineStyleConfigurator::SetValueLine(QLineEdit *value_line) {
  value_line->setAlignment(Qt::AlignRight);
  SetLineEditStyle(value_line);
}

void LineStyleConfigurator::SetLineEditStyle(QLineEdit *line) {
  line->setStyleSheet(
      "QLineEdit {"
      "border: 1px solid green;"
      "border-radius: 7px;"
      "background: black;"
      "selection-background-color: #40494D;"
      "color: green;"
      "font-weight: bold;"
      "}");
}
