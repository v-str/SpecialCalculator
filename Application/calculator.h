#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

#include <memory>

#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include "former.h"
#include "multiplyer.h"
#include "style_maker.h"

class QClipboard;

class Calculator : public QWidget {
  Q_OBJECT

  typedef unsigned int Style;

 public:
  explicit Calculator(QWidget* parent = nullptr);
  ~Calculator();

 public slots:
  void CalculateResult(const QString& result);
  void SetCoefficient(const QString& coefficient);

  void SetProgrammingStyle();
  void SetOfficeStyle();
  void SetMoto();

 signals:
  void CompletedDoubleValue(double complete_value);
  void CompleteQStringValue(const QString& complete_value);

  ////

 private:
  void SetConnections();

  void SetApplicationStyle(Style style = 0);
  void SetMainWindowStyle(Style style);

  QClipboard* clipboard_ = nullptr;
  Multiplyer* multipyer_ = nullptr;
  Former* former_ = nullptr;
  StyleMaker* style_maker_ = nullptr;

  double coefficient_ = 1.18;
};

#endif  // CALCULATOR_H
