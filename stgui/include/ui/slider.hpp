#pragma once

#include "widget.hpp"

namespace st {
namespace ui {
class Slider : public Widget {
public:
    Slider() = default;
    virtual ~Slider() = default;

    SIGNAL(Updated,void,int)
    CONNECT(Updated,mSigUpdated,sigUpdated_t)
};
} // namespace ui
} // namespace st
