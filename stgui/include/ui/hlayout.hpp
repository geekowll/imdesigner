#pragma once

#include "layout.hpp"

namespace st {
namespace ui {

class HLayout final: public Layout {
public:
    HLayout() = default;
    virtual ~HLayout() = default;

    void paint() override{}
};
} // namespace ui
} // namespace st
