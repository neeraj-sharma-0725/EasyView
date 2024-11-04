#include <bar/MenuBar.h>

MenuBar::MenuBar(QWidget *parent): QMenuBar(parent) {
  this->setStyleSheet("QMenuBar { background-color: #2d2d2d; color: white; }"
                       "QMenuBar::item { spacing: 3px; padding: 3px 10px; background: transparent; }"
                       "QMenuBar::item:selected { background: #3d3d3d; }");
}

MenuBar::~MenuBar() {
}