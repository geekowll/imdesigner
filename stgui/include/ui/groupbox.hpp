#pragma once

#include "widget.hpp"

namespace st {
namespace ui {
class GroupBox : public Widget {
public:
    GroupBox() = default;
    virtual ~GroupBox() = default;

    void paint() override;
};
} // namespace ui
} // namespace st
