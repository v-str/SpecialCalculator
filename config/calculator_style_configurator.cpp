#include "calculator_style_configurator.h"

CaclulatorStyleConfigurator::CaclulatorStyleConfigurator()
    : coefficient_line_(new QLineEdit),
      value_line_(new QLineEdit),
      lcd_(new QLCDNumber(16)),
      coefficient_label_(new QLabel),
      number_label_(new QLabel),
      result_label_(new QLabel),
      coefficient_checkbox_(new QCheckBox),
      grid_layout_(new QGridLayout),
      horizontal_layout_(new QHBoxLayout) {}

void CaclulatorStyleConfigurator::SetStyle(
    CaclulatorStyleConfigurator::AppTheme theme) {
  SetCoefficientLine(coefficient_line_, theme);
  SetValueLine(value_line_, theme);
  SetLCDNumber(lcd_, theme);
  SetCoefficientLabel(coefficient_label_, "Coefficient", 10, theme);
  SetNumberLabel(number_label_, "Number:", 14, theme);
  SetResultLabel(result_label_, "Result:", 16, theme);
  SetCheckBox(coefficient_checkbox_, theme);

  SetHorizontalLayout(horizontal_layout_, coefficient_label_,
                      coefficient_checkbox_, coefficient_line_);

  SetGridLayout(grid_layout_, value_line_, number_label_, result_label_, lcd_);
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

void CaclulatorStyleConfigurator::SetCoefficientLine(QLineEdit *line,
                                                     AppTheme theme) {
  line->setDisabled(true);
  line->setAlignment(Qt::AlignRight);
  line->setText("1.18");
  line->setMaximumSize(75, 25);
  SetLineEditStyle(line, theme);
}

void CaclulatorStyleConfigurator::SetValueLine(QLineEdit *line,
                                               AppTheme theme) {
  line->setAlignment(Qt::AlignRight);
  SetLineEditStyle(line, theme);
}

void CaclulatorStyleConfigurator::SetLineEditStyle(QLineEdit *line,
                                                   AppTheme theme) {
  switch (theme) {
    case kProgrammer:
      SetLineStyleSheet(line, "green", "black", "#40494D", "green", "bold");
      break;
    case kMoto:
      SetLineStyleSheet(line, "#000099", "white", "#40494D", "black", "bold");
      break;
    case kOffice:
      SetLineStyleSheet(line, "black", "#606060", "#40494D", "black", "normal");
      break;
  }
}

void CaclulatorStyleConfigurator::SetLineStyleSheet(
    QLineEdit *line, const QString &border_color, const QString &background,
    const QString &selection_color, const QString &text_color,
    const QString &font_weight) {
  line->setStyleSheet(
      "QLineEdit {"
      "border: 2px solid " +
      border_color + ";" + "border-radius: 7px;" + "background: " + background +
      ";" + "selection-background-color: " + selection_color + ";" + "color: " +
      text_color + ";" + "font-weight: " + font_weight + ";}");
}

void CaclulatorStyleConfigurator::SetLCDNumber(QLCDNumber *lcd,
                                               AppTheme theme) {
  lcd->setAutoFillBackground(true);
  lcd->setSegmentStyle(QLCDNumber::Flat);
  lcd->setFrameStyle(QFrame::NoFrame);

  SetLCDStyle(lcd, theme);
}

void CaclulatorStyleConfigurator::SetLCDStyle(QLCDNumber *lcd, AppTheme theme) {
  switch (theme) {
    case kProgrammer:
      SetLCDStyleSheet(lcd, "green", "black", "green");
      break;
    case kMoto:
      SetLCDStyleSheet(lcd, "#000099", "white", "black");
      break;
    case kOffice:
      SetLCDStyleSheet(lcd, "black", "#606060", "black");
      break;
  }
}

void CaclulatorStyleConfigurator::SetLCDStyleSheet(QLCDNumber *lcd,
                                                   const QString &border_color,
                                                   const QString &background,
                                                   const QString &value_color) {
  lcd->setStyleSheet(
      "QLCDNumber {"
      "border: 2px solid " +
      border_color + ";" + "border-radius: 7px;" + "background: " + background +
      ";" + "color: " + value_color + ";}");
}

void CaclulatorStyleConfigurator::SetCoefficientLabel(
    QLabel *label, const QString &text_of_label, int label_size,
    AppTheme theme) {
  switch (theme) {
    case kProgrammer:
      label->setText("<font color='green'>" + text_of_label + "</font>");
      label->setStyleSheet("background-color: black;");
      break;
    case kMoto:
      label->setText("<font color='green'> </font>");
      label->setStyleSheet("background-color: white;");
      break;
    case kOffice:
      label->setText("<font color=#CC6600>" + text_of_label + "</font>");
      label->setStyleSheet("background-color: #404040;");
      break;
  }
  label->setFont(GetFont(label_size));
}
void CaclulatorStyleConfigurator::SetNumberLabel(QLabel *label,
                                                 const QString &text_of_label,
                                                 int label_size,
                                                 AppTheme theme) {
  switch (theme) {
    case kProgrammer:
      label->setText("<font color='green'>" + text_of_label + "</font>");
      label->setStyleSheet("background-color: black;");
      break;
    case kMoto:
      label->setText("<font color='green'> </font>");
      label->setStyleSheet("background-image: url(:/motogp_logo.jpeg)");
      break;
    case kOffice:
      label->setText("<font color=#CC6600>" + text_of_label + "</font>");
      label->setStyleSheet("background-color: #404040;");
      break;
  }
  label->setFont(GetFont(label_size));
}
void CaclulatorStyleConfigurator::SetResultLabel(QLabel *label,
                                                 const QString &text_of_label,
                                                 int label_size,
                                                 AppTheme theme) {
  switch (theme) {
    case kProgrammer:
      label->setText("<font color='green'>" + text_of_label + "</font>");
      label->setStyleSheet("background-color: black;");
      break;
    case kMoto:
      label->setText("<font color='green'> </font>");
      label->setStyleSheet("background-image: url(:/moto.jpg)");
      break;
    case kOffice:
      label->setText("<font color=#CC6600>" + text_of_label + "</font>");
      label->setStyleSheet("background-color: #404040;");
      break;
  }
  label->setFont(GetFont(label_size));
}
QFont CaclulatorStyleConfigurator::GetFont(int point_size) {
  QFont font;
  font.setPointSize(point_size);

  return font;
}

void CaclulatorStyleConfigurator::SetCheckBox(QCheckBox *checkbox,
                                              AppTheme theme) {
  switch (theme) {
    case kProgrammer:
      checkbox->setStyleSheet(
          "QCheckBox::indicator {"
          "width: 15px;"
          "height: 15px;"
          "}"
          "QCheckBox::indicator:unchecked {"
          "border: 2px solid #084913;"
          "border-radius: 5px;"
          "background-color: black;"
          "}"
          "QCheckBox::indicator:checked {"
          "border: 2px solid #084913;"
          "border-radius: 5px;"
          "background-color: #00FF00;"
          "}");
      break;
    case kMoto:
      checkbox->setStyleSheet(
          "QCheckBox::indicator {"
          "width: 17px;"
          "height: 17px;"
          "}"
          "QCheckBox::indicator:unchecked {"
          "border: 2px solid #000099;"
          "border-radius: 5px;"
          "background-color: white;"
          "}"
          "QCheckBox::indicator:checked {"
          "border: 2px solid #000099;"
          "border-radius: 5px;"
          "background-color: #0080FF;"
          "}");

      break;
    case kOffice:
      checkbox->setStyleSheet(
          "QCheckBox::indicator {"
          "width: 15px;"
          "height: 15px;"
          "}"
          "QCheckBox::indicator:unchecked {"
          "border: 2px solid black;"
          "border-radius: 5px;"
          "background-color: #606060;"
          "}"
          "QCheckBox::indicator:checked {"
          "border: 2px solid black;"
          "border-radius: 5px;"
          "background-color: #CC6600;"
          "}");
      break;
  }
}

void CaclulatorStyleConfigurator::SetGridLayout(QGridLayout *grid_layout,
                                                QLineEdit *line_edit,
                                                QLabel *number_label,
                                                QLabel *result_label,
                                                QLCDNumber *lcd) {
  grid_layout->addLayout(horizontal_layout_, 0, 0, 1, 2);
  grid_layout->addWidget(number_label, 1, 1);
  grid_layout->addWidget(line_edit, 2, 1);
  grid_layout->addWidget(result_label, 3, 0, 2, 2);
  grid_layout->addWidget(lcd, 5, 1, 1, 2);
  grid_layout->setSpacing(1);
}

void CaclulatorStyleConfigurator::SetHorizontalLayout(QHBoxLayout *layout,
                                                      QLabel *label,
                                                      QCheckBox *checkbox,
                                                      QLineEdit *line_edit) {
  layout->addWidget(label);
  layout->addWidget(checkbox, 1, Qt::AlignRight);
  layout->addWidget(line_edit);
}
