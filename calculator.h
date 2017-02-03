#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "calculator_style_configurator.h"

#include "multiplyer.h"

#include <QWidget>
#include <memory>

class QClipboard;

class Calculator : public QWidget {
  Q_OBJECT
 public:
  explicit Calculator(QWidget* parent = nullptr);

 public slots:
  void CalculateResult(const QString& result);

 signals:
  void CompletedDoubleValue(double complete_value);
  void CompleteQStringValue(const QString& complete_value);

 private:
  enum AppTheme { kProgrammer, kMoto, kOffice };

  void ConnectWidgets();

  void SetMainWindow(QGridLayout* layout);

  QClipboard* clipboard_ = nullptr;

  Multiplyer multipyer_;

  std::unique_ptr<CaclulatorStyleConfigurator> configurator_ = nullptr;

  double coefficient_ = 0.0;
};

#endif  // CALCULATOR_H
