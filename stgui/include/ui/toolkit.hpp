#pragma once

#include <iostream>
#include <utility>
#include <variant>
#include <any>
#include "imgui.h"

namespace st {
namespace ui {
namespace {

std::ostream& operator<<(std::ostream& out,ImVec2 const& vec){
    out << "{ x: " << vec.x << ":"
        << " y:" << vec.y << " }";
    
    return out;
}

std::ostream& operator<<(std::ostream& out, ImVec4 const& vec){
    out << "{ x: " << vec.x << ":"
        << " y:" << vec.y << ":"
        << " z:" << vec.z << ":"
        << " w:" << vec.w << " }";
    
    return out;
}

}
}
}
