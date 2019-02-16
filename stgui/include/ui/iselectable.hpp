#pragma once

#include "events.hpp"

namespace st {
namespace ui {

using namespace ext;

class ISelectable{
public:
    SIGNAL(Selected,void,bool)
    CONNECT(Selected,sigSelected,sigSelected_t)
};
}
}
