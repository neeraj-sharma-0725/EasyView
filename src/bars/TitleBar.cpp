#include <bars/TitleBar.h>
#include <buttons/PushButton.h>
#include <QHBoxLayout>
#include <QLabel>

TitleBar::TitleBar(const std::string &title, QWidget *parent): m_title{title}, QWidget{parent} {
  construct();
}

TitleBar::TitleBar(QWidget *parent): TitleBar("", parent) {
}

TitleBar::~TitleBar() {
}

void TitleBar::construct(){
  this->setFixedHeight(30);

  QHBoxLayout* layout{new QHBoxLayout(this)};
  layout->setContentsMargins(0, 0, 0, 0);

  if(!m_title.empty()){
    QLabel* label{new QLabel(QString::fromStdString(m_title), this)};
    layout->addWidget(label, Qt::AlignCenter);
  }

  PushButton* minimizeButton{new PushButton(MINIMIZE, this)};
  PushButton* maximizeButton{new PushButton(MAXIMIZE, this)};
  PushButton* closeButton{new PushButton(CLOSE, this)};

  layout->addWidget(minimizeButton);
  layout->addWidget(maximizeButton);
  layout->addWidget(closeButton);

  connect(minimizeButton, &PushButton::clicked, this, &TitleBar::minimize);
  connect(maximizeButton, &PushButton::clicked, this, &TitleBar::maximize);
  connect(closeButton, & PushButton::clicked, this, &TitleBar::close);
}
