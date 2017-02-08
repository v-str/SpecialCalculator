#include "style_maker.h"

#include "checkbox_styler.h"
#include "label_styler.h"
#include "lcd_styler.h"
#include "line_edit_styler.h"

StyleMaker::StyleMaker(Former* former) : former_(former) {}

void StyleMaker::SetStyle(Style style) {
  SetLabel(style);
  SetCheckBox(style);
  SetLineEdit(style);
  SetLCD(style);
}

void StyleMaker::SetLabel(Style style) {
  LabelStyler::SetLabel(former_->NumberLabel(), style);
  LabelStyler::SetLabel(former_->ResultLabel(), style);
}

void StyleMaker::SetCheckBox(Style style) {
  CheckBoxStyler::SetCheckBox(former_->StateCheckBox(), style);
  CheckBoxStyler::SetCheckBox(former_->ProgrammerCheckBox(), style);
  CheckBoxStyler::SetCheckBox(former_->OfficeCheckBox(), style);
  CheckBoxStyler::SetCheckBox(former_->MotoCheckBox(), style);
}

void StyleMaker::SetLineEdit(Style style) {
  LineEditStyler::SetLine(former_->CoefficientLine(), style);
  LineEditStyler::SetLine(former_->EditLine(), style);
}

void StyleMaker::SetLCD(Style style) {
  LCDStyler::StaticSetLCD(former_->LCDNumber(), style);
}
