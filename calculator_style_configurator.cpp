#include "calculator_style_configurator.h"

CaclulatorStyleConfigurator::CaclulatorStyleConfigurator()
    : coefficient_line_(new QLineEdit),
      value_line_(new QLineEdit),
      lcd_(new QLCDNumber(16)),
      coefficient_label_(new QLabel),
      result_label_(new QLabel),
      coefficient_checkbox_(new QCheckBox),
      grid_layout_(new QGridLayout),
      horizontal_layout_(new QHBoxLayout) {
  SetCoefficientLabel(coefficient_label_, "Coefficient:");
  SetCoefficientLabel(result_label_, "Result:", 14);

  SetCheckBox(coefficient_checkbox_);
}

void CaclulatorStyleConfigurator::SetStyle(
    CaclulatorStyleConfigurator::AppTheme theme) {
  if (theme == kProgrammer) {
    SetCoefficientLine(coefficient_line_);
    SetValueLine(value_line_);

    SetLCDNumber(lcd_);

    SetHorizontalLayout(horizontal_layout_, coefficient_label_,
                        coefficient_checkbox_, coefficient_line_);

    SetGridLayout(grid_layout_, value_line_, result_label_, lcd_);
  }
}

QLineEdit *CaclulatorStyleConfigurator::GetValueLine() { return value_line_; }

QLineEdit *CaclulatorStyleConfigurator::GetCoefficientLine() {
  return coefficient_line_;
}

QLCDNumber *CaclulatorStyleConfigurator::GetLCDNumber() { return lcd_; }

QCheckBox *CaclulatorStyleConfigurator::GetCoefficientCheckBox() {
  return coefficient_checkbox_;
}

QGridLayout *CaclulatorStyleConfigurator::GetLayout() { return grid_layout_; }

void CaclulatorStyleConfigurator::SetCoefficientLine(QLineEdit *line) {
  line->setDisabled(true);
  line->setAlignment(Qt::AlignRight);
  line->setText("1.18");
  line->setMaximumSize(75, 25);
  SetLineEditStyle(line);
}

void CaclulatorStyleConfigurator::SetValueLine(QLineEdit *line) {
  line->setAlignment(Qt::AlignRight);
  SetLineEditStyle(line);
}

void CaclulatorStyleConfigurator::SetLineEditStyle(QLineEdit *line) {
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

void CaclulatorStyleConfigurator::SetLCDNumber(QLCDNumber *lcd) {
  lcd->setAutoFillBackground(true);
  lcd->setSegmentStyle(QLCDNumber::Flat);
  lcd->setFrameStyle(QFrame::NoFrame);

  SetLCDStyle(lcd);
}

void CaclulatorStyleConfigurator::SetLCDStyle(QLCDNumber *lcd) {
  lcd->setStyleSheet(
      "QLCDNumber {"
      "border: 1px solid green;"
      "border-radius: 7px;"
      "background: black;"
      "color: green;"
      "}");
}

void CaclulatorStyleConfigurator::SetCoefficientLabel(
    QLabel *label, const QString &text_of_label, int label_size) {
  label->setText("<font color='green'>" + text_of_label + "</font>");
  label->setFont(GetFont(label_size));
}

QFont CaclulatorStyleConfigurator::GetFont(int point_size) {
  QFont font;
  font.setPointSize(point_size);

  return font;
}

void CaclulatorStyleConfigurator::SetCheckBox(QCheckBox *checkbox) {
  checkbox->setStyleSheet(
      "QCheckBox::indicator:unchecked {"
      "border: 3px solid #084913;"
      "border-radius: 5px;"
      "background-color: black;"
      "}"
      "QCheckBox::indicator:checked {"
      "border: 3px solid #084913;"
      "border-radius: 5px;"
      "background-color: #367240;"
      "}");
}

void CaclulatorStyleConfigurator::SetGridLayout(QGridLayout *grid_layout,
                                                QLineEdit *line_edit,
                                                QLabel *label,
                                                QLCDNumber *lcd) {
  grid_layout->addLayout(horizontal_layout_, 0, 0, 1, 2);
  grid_layout->addWidget(line_edit, 1, 1);
  grid_layout->addWidget(label, 2, 0, 2, 2);
  grid_layout->addWidget(lcd, 4, 1, 1, 2);
  grid_layout->setSpacing(1);
}

void CaclulatorStyleConfigurator::SetHorizontalLayout(QHBoxLayout *layout,
                                                      QLabel *label,
                                                      QCheckBox *checkbox,
                                                      QLineEdit *line_edit) {
  layout->addWidget(label);
  layout->addWidget(checkbox);
  layout->addWidget(line_edit);
}
