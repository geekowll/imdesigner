#pragma once

#include "widget.hpp"

namespace st {
namespace ui {

class LineEdit : public Widget {
public:
    LineEdit() = default;
    virtual ~LineEdit() = default;

    SIGNAL(TextChanged,void,std::string)
    CONNECT(TextChanged,mSigTextChanged,sigTextChanged_t)
};

} // namespace ui
} // namespace st
