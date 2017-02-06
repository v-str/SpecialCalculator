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
      horizontal_layout_(new QHBoxLayout),
      line_edit_styler(new LineEditStyleConfig) {}

void CaclulatorStyleConfigurator::SetStyle(config::Theme theme) {
  line_edit_styler->SetCoefficientLine(coefficient_line_, theme);
  line_edit_styler->SetValueLine(value_line_, theme);

  SetLCDNumber(lcd_, theme);
  SetLabel(coefficient_label_, "Coefficient", 10, theme);
  SetLabel(number_label_, "Number:", 14, theme);
  SetLabel(result_label_, "Result:", 16, theme);
  SetCheckBox(coefficient_checkbox_, theme);

  SetHorizontalLayout(horizontal_layout_, coefficient_label_,
                      coefficient_checkbox_, coefficient_line_);

  SetGridLayout(grid_layout_, number_label_, value_line_, result_label_, lcd_);
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

void CaclulatorStyleConfigurator::SetLCDNumber(QLCDNumber *lcd,
                                               config::Theme theme) {
  lcd->setAutoFillBackground(true);
  lcd->setSegmentStyle(QLCDNumber::Flat);
  lcd->setFrameStyle(QFrame::NoFrame);

  SetLCDStyle(lcd, theme);
}

void CaclulatorStyleConfigurator::SetLCDStyle(QLCDNumber *lcd,
                                              config::Theme theme) {
  switch (theme) {
    case config::kProgrammer:
      SetLCDStyleSheet(lcd, "green", "black", "green");
      break;
    case config::kMoto:
      SetLCDStyleSheet(lcd, "#000099", "white", "black");
      break;
    case config::kOffice:
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

void CaclulatorStyleConfigurator::SetLabel(QLabel *label,
                                           const QString &text_of_label,
                                           int label_size,
                                           config::Theme theme) {
  QString background = "color";
  QString image = "url(:/motogp_logo.jpg)";

  if (text_of_label == "Coefficient") {
    image = "white";
  } else if (text_of_label == "Number:") {
    background = "image";
  } else if (text_of_label == "Result:") {
    background = "image";
    image = "url(:/moto.jpg)";
  }

  switch (theme) {
    case config::kProgrammer:
      SetLabelStyleSheet(label, text_of_label, "green", "color", "black");
      break;
    case config::kMoto:
      SetLabelStyleSheet(label, "", "white", background, image);
      break;
    case config::kOffice:
      SetLabelStyleSheet(label, text_of_label, "#CC6600", "color", "#404040");
      break;
  }
  label->setFont(GetFont(label_size));
}

void CaclulatorStyleConfigurator::SetLabelStyleSheet(
    QLabel *label, const QString &text_of_label, const QString &text_color,
    const QString &background_format, const QString &background) {
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
QFont CaclulatorStyleConfigurator::GetFont(int point_size) {
  QFont font;
  font.setPointSize(point_size);

  return font;
}

void CaclulatorStyleConfigurator::SetCheckBox(QCheckBox *checkbox,
                                              config::Theme theme) {
  switch (theme) {
    case config::kProgrammer:
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
    case config::kMoto:
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
    case config::kOffice:
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
                                                QLabel *number_label,
                                                QLineEdit *line_edit,
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
