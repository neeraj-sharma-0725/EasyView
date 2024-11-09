#include <buttons/PushButton.h>

PushButton::PushButton(const std::string &label, QWidget *parent): QPushButton(QString::fromStdString(label), parent){
}

PushButton::~PushButton() = default;