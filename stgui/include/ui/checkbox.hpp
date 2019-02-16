#pragma once

#include "widget.hpp"

namespace st {
namespace ui {

class CheckBox : public Widget {
public:
    CheckBox() = default;
    virtual ~CheckBox() = default;

    SIGNAL(Checked,void,bool)
    CONNECT(Checked,mSigChecked,sigChecked_t)
};
} // namespace ui
} // namespace st
