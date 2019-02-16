#pragma once

#include "widget.hpp"

namespace st {
namespace ui {

class ComboBox : public Widget {
public:
    explicit ComboBox(const std::string& name,
             Widget* parent)
        :Widget(name,parent){}

    virtual ~ComboBox() = default;

    SIGNAL(SelectionChanged,void,int)
    CONNECT(SelectionChanged,mSigSelectionChanged,sigSelectionChanged_t)
};
} // namespace ui
} // namespace st
