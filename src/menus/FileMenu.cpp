#include <menus/FileMenu.h>
#include <QMessageBox>

FileMenu::FileMenu(std::string& name, QWidget* parent): QMenu(QString::fromStdString(name), parent){
  m_newAction = this->addAction("New");
  m_fileAction = this->addAction("Open");
  m_exitAction = this->addAction("Exit");

  connect(m_newAction, &QAction::triggered, this, &FileMenu::onNew);
  connect(m_fileAction, &QAction::triggered, this, &FileMenu::onOpen);
  connect(m_exitAction, &QAction::triggered, this, &FileMenu::close);
};

void FileMenu::onNew(){
  QMessageBox::information(this, "New", "New file created.");
}

void FileMenu::onOpen(){
  QMessageBox::information(this, "Open", "New file opened.");
}

FileMenu::~FileMenu(){
  delete m_newAction;
  delete m_fileAction;
  delete m_exitAction;
}

