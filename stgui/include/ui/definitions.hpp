#pragma once

#include "imgui.h"

namespace st {
namespace ui {

namespace  {

constexpr float BAR_WIDTH = 0.0f;
constexpr float BAR_HEIGHT = 30.0f;
constexpr float BAR_PADDING = 1.0f;

const ImVec2 TOOLBAR_BUTTON_DEFAULT_SIZE = {30,15};
const ImVec4 BG_COLOR = ImVec4(0.3f,0.3f,0.3f,1.0f);

#define PROPERTY_MOVE_SET(Name,Value) \
    void set##Name(decltype(Value) value){   \
    Value = std::move(value);  \
}

#define PROPERTY_GET(Name,Value) \
    decltype(Value) get##Name() const { \
    return Value; \
}

#define PROPERTY_SET(Name,Value) \
    void set##Name(decltype(Value) value){   \
    Value = value;  \
}

#define PROPERTY(Name,Value)  \
    PROPERTY_GET(Name,Value)  \
    PROPERTY_SET(Name,Value)

#define PROPERTY_GET_REF(Name,Value) \
    decltype(Value)& get##Name() { \
    return Value; \
}

#define PROPERTY_SET_REF(Name,Value) \
    void set##Name(decltype(Value)& value){   \
    Value = value;  \
}

#define PROPERTY_REF(Name,Value)  \
    PROPERTY_GET_REF(Name,Value)  \
    PROPERTY_SET_REF(Name,Value)

#define PROPERTY_CONST_GET(Name,Value) \
    const auto& get##Name() const { \
    return Value; \
}

#define PROPERTY_CONST_SET(Name,Value) \
    void set##Name(decltype(Value) const& value){   \
    Value = value;  \
}

#define PROPERTY_CONST(Name,Value)  \
    PROPERTY_CONST_GET(Name,Value)  \
    PROPERTY_CONST_SET(Name,Value)

#define ANY_TO_FLOAT(Value) \
    float value = std::any_cast<float>(Value);

#define ANY_TO_VEC2(Value)  \
    ImVec2 value = std::any_cast<ImVec2>(Value);

#define ANY_TO_PUSHSTYLEVAR(Value)  \
    if(Value.type() == typeid(float)){  \
    auto f = std::any_cast<float>(Value); \
    ImGui::PushStyleVar(key,f);  \
}else if{    \
    auto v = std::any_cast<ImVec2>(Value);   \
    ImGui::PushStyleVar(key,v); \
}

#define VARIANT_TO_PUSHSTYLEVAR(Value)  \
    if(auto var = std::get_if<float>(&value)){  \
    ImGui::PushStyleVar(key,*var);  \
}else if(auto var = std::get_if<ImVec2>(&value)) {  \
    ImGui::PushStyleVar(key,*var);  \
}else  \
    throw "undefined style var type";
}
}
}
