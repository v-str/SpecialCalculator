#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

#include <memory>

#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include "calculator_style_config.h"
#include "multiplyer.h"
#include "theme_configuration.h"

class QClipboard;

class Calculator : public QWidget {
  Q_OBJECT
 public:
  explicit Calculator(QWidget* parent = nullptr);

 public slots:
  void CalculateResult(const QString& result);
  void SetCoefficient(const QString& coefficient);

  void SetProgrammerTheme();
  void SetOfficeTheme();
  void SetMotoTheme();

 signals:
  void CompletedDoubleValue(double complete_value);
  void CompleteQStringValue(const QString& complete_value);

 private:
  void SetAppStyle(config::Theme theme = config::kProgrammer);
  void SetMainWindow(config::Theme theme);
  void SetConnections();

  void SetMenuBar(QMenu* menu);
  void SetAppearanceMenu();

  void SetStyleMenuBar(config::Theme theme);
  void SetStyleMenu(config::Theme theme);

  QClipboard* clipboard_ = nullptr;

  std::unique_ptr<Multiplyer> multipyer_ = nullptr;
  std::unique_ptr<CaclulatorStyleConfig> configurator_ = nullptr;

  QMenuBar* menu_bar_ = nullptr;
  QMenu* appearance_menu_ = nullptr;

  QAction* programmer_ = nullptr;
  QAction* office_ = nullptr;
  QAction* moto_ = nullptr;

  double coefficient_ = 1.18;
};

#endif  // CALCULATOR_H
