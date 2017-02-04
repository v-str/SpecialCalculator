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
      appearance_menu_(new QMenu(tr("Appearance"))),
      about_menu_(new QMenu(tr("About"))),
      menu_bar_(new QMenuBar),
      programmer_(new QAction(tr("Programmer"), this)),
      moto_(new QAction(tr("Moto"), this)),
      office_(new QAction(tr("Office"), this)) {
  SetAppStyle(kProgrammer);
  SetMainWindow(kProgrammer);
  SetConnections();

  //  QAction *programmer_theme = new QAction(tr("Programmer"), this);
  //  QAction *moto_theme = new QAction(tr("Moto"), this);
  //  QAction *office_theme = new QAction(tr("Office"), this);

  //  QMenuBar *menuBar = new QMenuBar();
  //  menuBar->setStyleSheet(
  //      "QMenuBar::item {"
  //      "spacing: 20px;"
  //      "background: black;"
  //      "border: 1px solid green;"
  //      "border-radius: 2px;"
  //      "padding: 1px 4px;"
  //      "}"
  //      "QMenuBar {"
  //      "color: #0080FF;"
  //      "}");

  //  QMenu *menu = new QMenu("Appearance");

  //  QMenu *about = new QMenu("About");

  //  menuBar->addMenu(menu);
  //  menuBar->addMenu(about);

  //  menu->addAction(programmer_theme);
  //  menu->addAction(moto_theme);
  //  menu->addAction(office_theme);

  SetMenu();
  SetMenuBar(appearance_menu_);
  SetMenuBar(about_menu_);

  layout()->setMenuBar(menu_bar_);
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
}

void Calculator::CalculateResult(const QString &value) {
  multipyer_->SetCoefficient(coefficient_);
  multipyer_->SetNumber(value);

  clipboard_->setText(multipyer_->GetCompleteStringValue());

  emit CompletedDoubleValue(multipyer_->GetCompleteDoubleValue());
}

void Calculator::SetCoefficient(const QString &coefficient) {
  coefficient_ = coefficient.toDouble();
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
}

void Calculator::SetMainWindow(AppTheme theme) {
  QGridLayout *layout = configurator_->GetLayout();
  setLayout(layout);
  setFixedSize(225, 260);
  setWindowTitle("Calculator");

  switch (theme) {
    case kProgrammer:
      setStyleSheet("background-color:black;");
      SetStyleMenuBar(theme);
      break;
    case kMoto:
      break;
    case kOffice:
      break;
  }
}

void Calculator::SetMenuBar(QMenu *menu) { menu_bar_->addMenu(menu); }

void Calculator::SetMenu() {
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
      SetStyleMenu(theme);
      break;
  }
}

void Calculator::SetStyleMenu(Calculator::AppTheme theme) {
  switch (theme) {
    case kProgrammer:
      appearance_menu_->setStyleSheet(
          "QMenu {"
          "background-color: black;"
          "border: 1px solid green;"
          "color: green;"
          "}"
          "QMenu::item:selected {"
          "background-color: #202020;"
          "}");
      break;
  }
}
