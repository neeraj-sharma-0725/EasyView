#include <Application.h>
#include <windows/MainWindow.h>

Application::Application(int argc, char **argv): QApplication(argc, argv){
  m_mainWindow = new MainWindow();
  decorate();
  m_mainWindow->show();
}

Application::~Application(){
  delete m_mainWindow;
}

void Application::decorate(){
  QFile file = QFile("./resources/style.css");
  if(file.open(QFile::ReadOnly)){
      QString styleSheet = QLatin1String(file.readAll());
      this->setStyleSheet(styleSheet);
  }
}
