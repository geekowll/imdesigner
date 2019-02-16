#pragma once

#include "widget.hpp"

namespace st {
namespace ui {

class ProgressBar : public Widget {
public:
    ProgressBar() = default;
    virtual ~ProgressBar() = default;

    SIGNAL(Updated,void,int)
    CONNECT(Updated,mSigUpdated,sigUpdated_t)
};
} // namespace ui
} // namespace st
