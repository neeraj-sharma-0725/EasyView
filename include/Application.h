#pragma once

#include <QApplication>
#include <QFile>
#include <QLatin1String>

class MainWindow;

class Application: public QApplication {
  Q_OBJECT

public:
  explicit Application(int, char**);
  ~Application();

private:
  void decorate();

private:
  MainWindow* m_mainWindow;
};