#pragma once

#include "widget.hpp"

namespace st {
namespace ui {

class MessageBox : public Widget {
public:
    MessageBox() = default;
    virtual ~MessageBox() = default;

    SIGNAL(Clicked,void,int)
    CONNECT(Click,mSigClicked,sigClicked_t)
};
} // namespace ui
} // namespace st
