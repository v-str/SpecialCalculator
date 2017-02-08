#include "calculator.h"

#include <QApplication>
#include <QClipboard>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent),
      clipboard_(QApplication::clipboard()),
      multipyer_(new Multiplyer),
      former_(new Former),
      style_maker_(new StyleMaker(former_))

{
  QGridLayout *grid_layout = former_->GridLayout();
  setLayout(grid_layout);
  SetApplicationStyle();
  SetConnections();
}

void Calculator::SetConnections() {
  QLineEdit *edit_line = former_->EditLine();
  connect(edit_line, SIGNAL(returnPressed()), edit_line, SLOT(clear()));
  connect(edit_line, SIGNAL(textChanged(QString)),
          SLOT(CalculateResult(QString)));

  QLineEdit *coefficient_line = former_->CoefficientLine();
  QCheckBox *coeficient_checkbox = former_->StateCheckBox();
  connect(coeficient_checkbox, SIGNAL(clicked(bool)), coefficient_line,
          SLOT(setEnabled(bool)));
  connect(coefficient_line, SIGNAL(textChanged(QString)),
          SLOT(SetCoefficient(QString)));

  QLCDNumber *lcd = former_->LCDNumber();
  connect(this, SIGNAL(CompletedDoubleValue(double)), lcd,
          SLOT(display(double)));

  QCheckBox *prgm_button = former_->ProgrammerCheckBox();
  connect(prgm_button, SIGNAL(clicked(bool)), SLOT(SetProgrammingStyle()));
  QCheckBox *office_button = former_->OfficeCheckBox();
  connect(office_button, SIGNAL(clicked(bool)), SLOT(SetOfficeStyle()));
  QCheckBox *moto_button = former_->MotoCheckBox();
  connect(moto_button, SIGNAL(clicked(bool)), SLOT(SetMoto()));
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

void Calculator::SetProgrammingStyle() {
  former_->OfficeCheckBox()->setChecked(false);
  former_->MotoCheckBox()->setChecked(false);
  SetApplicationStyle(0);
}

void Calculator::SetOfficeStyle() {
  former_->ProgrammerCheckBox()->setChecked(false);
  former_->MotoCheckBox()->setChecked(false);
  SetApplicationStyle(1);
}

void Calculator::SetMoto() {
  former_->ProgrammerCheckBox()->setChecked(false);
  former_->OfficeCheckBox()->setChecked(false);
  SetApplicationStyle(2);
}

void Calculator::SetApplicationStyle(Calculator::Style style) {
  switch (style) {
    case 0:
      style_maker_->SetStyle(style);
      break;
    case 1:
      style_maker_->SetStyle(style);
      break;
    case 2:
      style_maker_->SetStyle(style);
      break;
  }
  SetMainWindowStyle(style);
}

void Calculator::SetMainWindowStyle(Calculator::Style style) {
  setFixedSize(225, 300);
  setWindowTitle("Calculator");
  switch (style) {
    case 0:
      setStyleSheet("background-color:black;");
      break;
    case 1:
      setStyleSheet("background-color:#404040");
      break;
    case 2:
      setStyleSheet("background-color:white;");
      break;
  }
}