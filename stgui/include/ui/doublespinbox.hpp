#pragma once

#include "spinbox.hpp"

namespace st {
namespace ui {

class DoubleSpinBox final: public SpinBox{
public:
    explicit DoubleSpinBox(const std::string& name,Widget* parent)
        :SpinBox(name,parent){}

    ~DoubleSpinBox() = default;
};
}
}
