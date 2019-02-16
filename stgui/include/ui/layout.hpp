#pragma once

#include <algorithm>
#include <deque>
#include <memory>
#include "imgui.h"
#include "widget.hpp"

namespace st {
namespace ui {

class Layout{
public:
    Layout(Widget* parent);
    virtual ~Layout() = default;

    enum class Direction { VERTICAL = 0, HORIZONTAL };

    virtual void paint() = 0;

    virtual void addWidget(std::shared_ptr<Widget> widget);

    virtual void removeWidget(const std::string &key);

    void changeDirection(Direction from, Direction to);

private:
    std::deque<std::shared_ptr<Widget>> mWidgets;
    Widget* mParent;
    ImVec2 mSize;

public:
    PROPERTY_CONST(Parent,mParent)
    PROPERTY_CONST(Size,mSize)
};
} // namespace ui
} // namespace st
