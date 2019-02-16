#pragma once

#include <variant>
#include <any>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <unordered_map>
#include <map>
#include <memory>
#include <optional>

#include "imgui.h"
#include "toolkit.hpp"
#include "events.hpp"
#include "definitions.hpp"
#include "idrawable.hpp"
#include "enums.hpp"


namespace st {
namespace ui {

class Layout;

class Widget: public IDrawable {
public:
    Widget() = default;
    
    explicit Widget(const std::string& name,
                    Widget* parent = nullptr,
                    ImGuiWindowFlags flags = ImGuiWindowFlags_None);
    
    virtual ~Widget();
    
    Widget(Widget&& other) = default;
    
    Widget(const Widget& other) = default;
    
    Widget& operator=(Widget&& other) = default;
    
    Widget& operator=(const Widget& other) = default;
    
    bool operator==(const Widget& other);
    
    void draw() final override;
    
    void setSizeMinMax(ImVec2 const& min, ImVec2 const& max);
    
    template <typename FType>
    void connect(FType func){}
    
protected:
    std::string mName;
    ImVec2 mSize;
    ImVec2 mOffset;
    Widget* mParent;
    
    float &mWidth = mSize.x;
    float &mHeight = mSize.y;
    
    std::shared_ptr<Layout> mLayout;
    
    bool mBorder = false;
    ImGuiWindowFlags mFlags;
    bool mVisible = true;
    
    struct SizeMinMax_{
        ImVec2 min;
        ImVec2 max;
    }mSizeMinMax;
    
public:
    template <typename T>
    void setStyle(ImGuiStyleVar_ target, T&& value){
        mStyleMap.insert_or_assign(target,value);
    }
    
    void setColor(ImGuiCol_ target, ImVec4 const& value){
        mColorMap.insert_or_assign(target,value);
    }
    
    PROPERTY_CONST(Flags,mFlags)
    PROPERTY_CONST(Size,mSize)
    PROPERTY_GET_REF(Size,mSize)
    PROPERTY(Layout,mLayout)
    PROPERTY_REF(Width,mWidth)
    PROPERTY_REF(Height,mHeight)
    PROPERTY_CONST(Border,mBorder)
    PROPERTY_CONST_GET(Parent,mParent)
    PROPERTY_CONST_GET(Name,mName);
    PROPERTY_CONST(Offset,mOffset);
    PROPERTY_CONST(Visible,mVisible);
    
protected:
    std::unordered_map<ImGuiCol_, ImVec4>  mColorMap;
    std::unordered_map<ImGuiStyleVar_,std::variant<float,ImVec2>>mStyleMap;
    
    std::vector<Widget*> mChildren;
    
protected:
    void paint() override;
    
    using const_iterator = std::vector<Widget*>::const_iterator;
    using iterator = std::vector<Widget*>::iterator;
    
    void setParent(Widget* parent);
    
    void addChild(Widget* child){ mChildren.emplace_back(child); }
    
    void removeChild(Widget* child);
    
    std::pair<bool,iterator> hasChild(const std::string& name);
    
    std::pair<bool,const_iterator> hasChild(const std::string& name) const;
};
} // namespace ui
} // namespace st
