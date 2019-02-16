#pragma once

#include "widget.hpp"

namespace st {
namespace ui {

class SpinBox : public Widget {
public:
    SpinBox(const std::string& name,Widget* parent);
    virtual ~SpinBox() = default;

    SIGNAL(Updated,void,int)
    CONNECT(Updated,mSigUpdated,sigUpdated_t)
};
} // namespace ui
} // namespace st
