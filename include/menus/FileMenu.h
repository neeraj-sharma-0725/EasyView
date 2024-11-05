#pragma once

#include <QMenu>

class FileMenu : public QMenu {
  Q_OBJECT

public:
  FileMenu(std::string&, QWidget* parent = nullptr);
  ~FileMenu();

private slots:
  void onNew();
  void onOpen();

signals:
  void close();

private:
  QAction *m_newAction;
  QAction *m_fileAction;
  QAction *m_exitAction;
};