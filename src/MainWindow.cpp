#include <MainWindow.h>
#include <QGraphicsDropShadowEffect>

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
  QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
  shadow->setBlurRadius(20);
  shadow->setOffset(0, 5);
  shadow->setColor(Qt::gray);
  this->setGraphicsEffect(shadow);
  setStyleSheet("background-color: white; border-radius: 10px;");
  resize(400, 300);
}

MainWindow::~MainWindow() {
  delete m_fileMenu;
  delete m_menuBar;
}
