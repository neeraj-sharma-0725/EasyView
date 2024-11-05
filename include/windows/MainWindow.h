#pragma once

#include <QMainWindow>

class MenuBar;
class FileMenu;

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