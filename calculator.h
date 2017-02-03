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
  enum AppTheme { kProgrammer, kMoto, kOffice };

  explicit Calculator(QWidget* parent = nullptr);

 public slots:
  void CalculateResult(const QString& result);
  void SetCoefficient(const QString& coefficient);

 signals:
  void CompletedDoubleValue(double complete_value);
  void CompleteQStringValue(const QString& complete_value);

 private:
  void SetAppStyle(AppTheme theme);
  void SetMainWindow();
  void SetConnections();

  QClipboard* clipboard_ = nullptr;

  std::unique_ptr<Multiplyer> multipyer_ = nullptr;

  std::unique_ptr<CaclulatorStyleConfigurator> configurator_ = nullptr;

  double coefficient_ = 1.18;
};

#endif  // CALCULATOR_H
