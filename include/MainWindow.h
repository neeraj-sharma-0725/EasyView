#pragma once

#include <QMainWindow>
#include <bar/MenuBar.h>
#include <menu/FileMenu.h>

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  MainWindow(QWidget * parent = nullptr);
  virtual ~MainWindow();

private:
  void decorateWindow();

private:
  MenuBar* m_menuBar;
  FileMenu* m_fileMenu;
};