#pragma once

#include "widget.hpp"

namespace st {
namespace ui {

class ListView : public Widget {
public:
    ListView() = default;
    virtual ~ListView() = default;

    SIGNAL(SelectionChanged,void,int)
    CONNECT(SelectionChanged,mSigSelectionChanged,sigSelectionChanged_t)
};
} // namespace ui
} // namespace st
