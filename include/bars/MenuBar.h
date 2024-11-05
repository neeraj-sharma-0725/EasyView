#pragma once

#include <QMenuBar>

class MenuBar : public QMenuBar {
  Q_OBJECT

public:
  explicit MenuBar(QWidget* parent = nullptr);
  ~MenuBar();
};