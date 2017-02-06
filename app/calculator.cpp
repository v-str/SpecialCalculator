#include "calculator.h"

#include <QApplication>
#include <QClipboard>

#include <QAction>
#include <QMenu>
#include <QMenuBar>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent),
      clipboard_(QApplication::clipboard()),
      multipyer_(new Multiplyer),
      configurator_(new CaclulatorStyleConfigurator),
      menu_bar_(new QMenuBar),
      appearance_menu_(new QMenu(tr("Appearance"))),
      programmer_(new QAction(tr("Programmer"), this)),
      moto_(new QAction(tr("Moto"), this)),
      office_(new QAction(tr("Office"), this)) {
  SetAppStyle();
  SetConnections();
  SetAppearanceMenu();
  SetMenuBar(appearance_menu_);

  layout()->setMenuBar(menu_bar_);
}

void Calculator::SetAppStyle(Calculator::AppTheme theme) {
  switch (theme) {
    case kProgrammer:
      configurator_->SetStyle(CaclulatorStyleConfigurator::kProgrammer);
      break;
    case kMoto:
      configurator_->SetStyle(CaclulatorStyleConfigurator::kMoto);
      break;
    case kOffice:
      configurator_->SetStyle(CaclulatorStyleConfigurator::kOffice);
      break;
  }
  SetMainWindow(theme);
}

void Calculator::SetConnections() {
  QLineEdit *value_line = configurator_->GetValueLine();
  QLineEdit *coefficient_line = configurator_->GetCoefficientLine();
  QLCDNumber *lcd = configurator_->GetLCDNumber();
  QCheckBox *coef_checkbox = configurator_->GetCoefficientCheckBox();

  connect(value_line, SIGNAL(returnPressed()), value_line, SLOT(clear()));
  connect(value_line, SIGNAL(textChanged(QString)),
          SLOT(CalculateResult(QString)));
  connect(this, SIGNAL(CompletedDoubleValue(double)), lcd,
          SLOT(display(double)));
  connect(coef_checkbox, SIGNAL(clicked(bool)), coefficient_line,
          SLOT(setEnabled(bool)));
  connect(coefficient_line, SIGNAL(textChanged(QString)),
          SLOT(SetCoefficient(QString)));

  connect(programmer_, SIGNAL(triggered(bool)), SLOT(SetProgrammerTheme()));
  connect(moto_, SIGNAL(triggered(bool)), SLOT(SetMotoTheme()));
  connect(office_, SIGNAL(triggered(bool)), SLOT(SetOfficeTheme()));
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
  SetAppStyle(kProgrammer);
  SetMainWindow(kProgrammer);
}

void Calculator::SetMotoTheme() {
  SetAppStyle(kMoto);
  SetMainWindow(kMoto);
}

void Calculator::SetOfficeTheme() {
  SetAppStyle(kOffice);
  SetMainWindow(kOffice);
}

void Calculator::SetMainWindow(AppTheme theme) {
  QGridLayout *layout = configurator_->GetLayout();
  setLayout(layout);
  setFixedSize(225, 300);
  setWindowTitle("Calculator");

  switch (theme) {
    case kProgrammer:
      setStyleSheet("background-color:black;");
      break;
    case kMoto:
      setStyleSheet("background-color:white;");
      break;
    case kOffice:
      setStyleSheet("background-color:#404040");
      break;
  }
  SetStyleMenuBar(theme);
}

void Calculator::SetMenuBar(QMenu *menu) { menu_bar_->addMenu(menu); }

void Calculator::SetAppearanceMenu() {
  appearance_menu_->addAction(programmer_);
  appearance_menu_->addAction(moto_);
  appearance_menu_->addAction(office_);
}

void Calculator::SetStyleMenuBar(Calculator::AppTheme theme) {
  switch (theme) {
    case kProgrammer:
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
    case kMoto:
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
    case kOffice:
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
  }
  SetStyleMenu(theme);
}

void Calculator::SetStyleMenu(Calculator::AppTheme theme) {
  switch (theme) {
    case kProgrammer:
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
    case kMoto:
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
    case kOffice:
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
  }
}
