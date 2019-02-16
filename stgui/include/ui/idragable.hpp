#pragma once

#include "events.hpp"
#include "imgui.h"

namespace st {
namespace ui {


class IDragable {
public:
    virtual void drag() = 0;
    virtual void drop() = 0;

    SIGNAL(Dragging,void,ImVec2)
    CONNECT(Dragging,sigDragging,sigDragging_t)

    SIGNAL(Dropped,void,ImVec2)
    CONNECT(Dropped,sigDropped,sigDropped_t)
};
}
}
