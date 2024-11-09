#include <windows/MainWindow.h>
#include <QGraphicsDropShadowEffect>
#include <bars/MenuBar.h>
#include <menus/FileMenu.h>
#include <QVBoxLayout>
#include <bars/TitleBar.h>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {

  QWidget* centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QVBoxLayout* mainLayout = new QVBoxLayout();
  mainLayout->setContentsMargins(0,0,0,0);

  MenuBar* menuBar = new MenuBar(centralWidget);
  
  menuBar->addMenu(createFileMenu(centralWidget));
  this->setMenuBar(menuBar);
  mainLayout->addWidget(centralWidget);

  decorateWindow();
}

MainWindow::~MainWindow() = default;

void MainWindow::decorateWindow(){
  resize(400, 300);
}

TitleBar* MainWindow::createTitleBar(QWidget* parent){
  TitleBar* titleBar{new TitleBar("EasyView", parent)};
  
  // connect events
  connect(titleBar, &TitleBar::minimize, this, &MainWindow::showMinimized);
  connect(titleBar, &TitleBar::maximize, this, &MainWindow::showMaximized);
  connect(titleBar, &TitleBar::close, this, &MainWindow::close);
  return titleBar;
}

FileMenu* MainWindow::createFileMenu(QWidget* parent){
  std::string name("File");
  FileMenu* fileMenu = new FileMenu(name, parent);

  connect(fileMenu, &FileMenu::close, this, &MainWindow::close);
  return fileMenu;
}
