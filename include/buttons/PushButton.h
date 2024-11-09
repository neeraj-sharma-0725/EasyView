#pragma once

#include <QPushButton>

class PushButton : public QPushButton {
  Q_OBJECT
public:
  PushButton(const std::string& label, QWidget* parent = nullptr);
  ~PushButton();
};