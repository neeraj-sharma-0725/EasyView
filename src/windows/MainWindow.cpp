#include <windows/MainWindow.h>
#include <QGraphicsDropShadowEffect>
#include <bars/MenuBar.h>
#include <menus/FileMenu.h>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
  m_menuBar = new MenuBar(this);
  std::string name("File");
  m_fileMenu = new FileMenu(name, this);
  
  m_menuBar->addMenu(m_fileMenu);
  this->setMenuBar(m_menuBar);

  decorateWindow();
  connect(m_fileMenu, &FileMenu::close, this, &MainWindow::close);
}

void MainWindow::decorateWindow(){
  setStyleSheet("background-color: white; border-radius: 10px;");
  resize(400, 300);
}

MainWindow::~MainWindow() {
  delete m_fileMenu;
  delete m_menuBar;
}
