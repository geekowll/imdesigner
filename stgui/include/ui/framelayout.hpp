#pragma once

#include "layout.hpp"

namespace st {
namespace ui {

class FrameLayout: public Layout{
public:
    explicit FrameLayout(Widget* parent)
        :Layout(parent){}

    virtual ~FrameLayout() = default;

    void paint() override;
};

}
}
