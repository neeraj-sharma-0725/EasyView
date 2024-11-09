#pragma once

#include <QMainWindow>

class MenuBar;
class FileMenu;
class TitleBar;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  MainWindow(QWidget * parent = nullptr);
  virtual ~MainWindow();

private:
  void decorateWindow();
  TitleBar* createTitleBar(QWidget*);
  FileMenu* createFileMenu(QWidget*);
};