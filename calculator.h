#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "calculator_style_configurator.h"

#include "multiplyer.h"

#include <QWidget>
#include <memory>

#include <QAction>
#include <QMenu>
#include <QMenuBar>

class QClipboard;

class Calculator : public QWidget {
  Q_OBJECT
 public:
  enum AppTheme { kProgrammer, kMoto, kOffice };

  explicit Calculator(QWidget* parent = nullptr);

 public slots:
  void CalculateResult(const QString& result);
  void SetCoefficient(const QString& coefficient);

  void SetProgrammerTheme();
  void SetMotoTheme();
  void SetOfficeTheme();

 signals:
  void CompletedDoubleValue(double complete_value);
  void CompleteQStringValue(const QString& complete_value);

 private:
  void SetAppStyle(AppTheme theme = kProgrammer);
  void SetMainWindow(AppTheme theme);
  void SetConnections();

  void SetMenuBar(QMenu* menu);
  void SetAppearanceMenu();


  void SetStyleMenuBar(AppTheme theme);
  void SetStyleMenu(AppTheme theme);

  QClipboard* clipboard_ = nullptr;

  std::unique_ptr<Multiplyer> multipyer_ = nullptr;
  std::unique_ptr<CaclulatorStyleConfigurator> configurator_ = nullptr;

  QMenu* appearance_menu_ = nullptr;
  QMenuBar* menu_bar_ = nullptr;

  QAction* programmer_ = nullptr;
  QAction* moto_ = nullptr;
  QAction* office_ = nullptr;


  double coefficient_ = 1.18;
};

#endif  // CALCULATOR_H
