#include "calculator.h"

#include <QApplication>
#include <QClipboard>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent),
      clipboard_(QApplication::clipboard()),
      multipyer_(new Multiplyer),
      configurator_(new CaclulatorStyleConfig),
      menu_bar_(new QMenuBar),
      appearance_menu_(new QMenu(tr("Appearance"))),
      programmer_(new QAction(tr("Programmer"), this)),
      office_(new QAction(tr("Office"), this)),
      moto_(new QAction(tr("Moto"), this)) {
  SetAppStyle();
  SetAppearanceMenu();
  SetMenuBar(appearance_menu_);
  SetConnections();

  layout()->setMenuBar(menu_bar_);
}

void Calculator::SetAppStyle(config::Theme theme) {
  switch (theme) {
    case config::kProgrammer:
      configurator_->SetStyle(config::kProgrammer);
      break;
    case config::kOffice:
      configurator_->SetStyle(config::kOffice);
      break;
    case config::kMoto:
      configurator_->SetStyle(config::kMoto);
      break;
  }
  SetMainWindow(theme);
}

void Calculator::SetConnections() const {
  QLineEdit *value_line = configurator_->GetValueLine();
  connect(value_line, SIGNAL(returnPressed()), value_line, SLOT(clear()));
  connect(value_line, SIGNAL(textChanged(QString)),
          SLOT(CalculateResult(QString)));

  QLineEdit *coefficient_line = configurator_->GetCoefficientLine();
  QCheckBox *coef_checkbox = configurator_->GetCoefficientCheckBox();
  connect(coef_checkbox, SIGNAL(clicked(bool)), coefficient_line,
          SLOT(setEnabled(bool)));
  connect(coefficient_line, SIGNAL(textChanged(QString)),
          SLOT(SetCoefficient(QString)));

  QLCDNumber *lcd = configurator_->GetLCDNumber();
  connect(this, SIGNAL(CompletedDoubleValue(double)), lcd,
          SLOT(display(double)));

  connect(programmer_, SIGNAL(triggered(bool)), SLOT(SetProgrammerTheme()));
  connect(office_, SIGNAL(triggered(bool)), SLOT(SetOfficeTheme()));
  connect(moto_, SIGNAL(triggered(bool)), SLOT(SetMotoTheme()));
}

void Calculator::CalculateResult(const QString &value) {
  multipyer_->SetMultiplyCoefficient(coefficient_);
  multipyer_->SetNumber(value);

  clipboard_->setText(multipyer_->GetCompleteStringValue());

  emit CompletedDoubleValue(multipyer_->GetCompleteDoubleValue());
}

void Calculator::SetCoefficient(const QString &coefficient) {
  coefficient_ = coefficient.toDouble();
}

void Calculator::SetProgrammerTheme() {
  SetAppStyle(config::kProgrammer);
  SetMainWindow(config::kProgrammer);
}

void Calculator::SetOfficeTheme() {
  SetAppStyle(config::kOffice);
  SetMainWindow(config::kOffice);
}

void Calculator::SetMotoTheme() {
  SetAppStyle(config::kMoto);
  SetMainWindow(config::kMoto);
}

void Calculator::SetMainWindow(config::Theme theme) {
  QGridLayout *grid_layout = configurator_->GetLayout();
  setLayout(grid_layout);
  setFixedSize(225, 300);
  setWindowTitle("Calculator");

  switch (theme) {
    case config::kProgrammer:
      setStyleSheet("background-color:black;");
      break;
    case config::kOffice:
      setStyleSheet("background-color:#404040");
      break;
    case config::kMoto:
      setStyleSheet("background-color:white;");
      break;
  }
  SetStyleMenuBar(theme);
}

void Calculator::SetMenuBar(QMenu *menu) { menu_bar_->addMenu(menu); }

void Calculator::SetAppearanceMenu() {
  appearance_menu_->addAction(programmer_);
  appearance_menu_->addAction(office_);
  appearance_menu_->addAction(moto_);
}

void Calculator::SetStyleMenuBar(config::Theme theme) {
  switch (theme) {
    case config::kProgrammer:
      menu_bar_->setStyleSheet(
          "QMenuBar {"
          "background-color: black;"
          "color: green;"
          "}"
          "QMenuBar::item {"
          "border: 1px solid green;"
          "border-radius: 2px;"
          "padding: 1px 4px;"
          "}"
          "QMenuBar::item:selected {"
          "background-color: #202020;"
          "}");
      break;
    case config::kOffice:
      menu_bar_->setStyleSheet(
          "QMenuBar {"
          "background-color: #404040;"
          "color: black;"
          "}"
          "QMenuBar::item {"
          "border: 1px solid black;"
          "border-radius: 2px;"
          "padding: 1px 4px;"
          "background-color: #606060;"
          "}"
          "QMenuBar::item:selected {"
          "background-color: grey;"
          "}");
      break;
    case config::kMoto:
      menu_bar_->setStyleSheet(
          "QMenuBar {"
          "background-color: white;"
          "color: black;"
          "}"
          "QMenuBar::item {"
          "border: 2px solid #000099;"
          "border-radius: 7px;"
          "padding: 1px 4px;"
          "background-color: white;"
          "}"
          "QMenuBar::item:selected {"
          "background-color: #99CCFF;"
          "}");
      break;
  }
  SetStyleMenu(theme);
}

void Calculator::SetStyleMenu(config::Theme theme) {
  switch (theme) {
    case config::kProgrammer:
      appearance_menu_->setStyleSheet(
          "QMenu {"
          "background-color: black;"
          "border: 1px solid green;"
          "border-radius: 2px;"
          "color: green;"
          "}"
          "QMenu::item:selected {"
          "background-color: #202020;"
          "}");
      break;
    case config::kOffice:
      appearance_menu_->setStyleSheet(
          "QMenu {"
          "background-color: #606060;"
          "border: 1px solid black;"
          "border-radius: 2px;"
          "color: black;"
          "}"
          "QMenu::item:selected {"
          "background-color: grey;"
          "}");
      break;
    case config::kMoto:
      appearance_menu_->setStyleSheet(
          "QMenu {"
          "background-color: white;"
          "border: 2px solid #000099;"
          "border-radius: 8px;"
          "color: #000099;"
          "}"
          "QMenu::item:selected {"
          "background-color: #99CCFF;"
          "}");
      break;
  }
}
