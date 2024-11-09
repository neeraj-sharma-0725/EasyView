#pragma once

#include <QWidget>

class TitleBar : public QWidget {
  Q_OBJECT
public:
  TitleBar(const std::string& name, QWidget* parent = nullptr);
  TitleBar(QWidget* parent = nullptr);
  ~TitleBar();

private:
  void construct();


signals:
  void minimize();
  void maximize();
  void close();

private:
  std::string m_title;
  const std::string MINIMIZE{"-"};
  const std::string MAXIMIZE{"□"};
  const std::string CLOSE{"x"};
};