#pragma once

#include "widget.hpp"

namespace st {
namespace ui {

class RadioButton: public Widget {
public:
  RadioButton() = default;
  virtual ~RadioButton() = default;

  SIGNAL(SelectionChanged,void,bool)
  CONNECT(SelectionChanged,mSigSelectionChanged,sigSelectionChanged_t)
};
} // namespace ui
} // namespace st
