#pragma once

#include <list>
#include "widget.hpp"
#include "toolbarbutton.hpp"

namespace st {
namespace ui {

class ToolBar final: public Widget{
public:
    ToolBar() = default;
    
    virtual ~ToolBar() = default;
    
    explicit ToolBar(const std::string& name,
                     Widget* parent);
    
    ToolBar(const ToolBar& other) = default;
    
    ToolBar(ToolBar&& other) = default;
    
    ToolBar& operator=(const ToolBar& other) = default;
    
    ToolBar& operator=(ToolBar&& other) = default;
    
protected:
    void paint() override;
    
public:
    ToolBarButton& addButton(const std::string& title);
    
    ToolBarButton& addButton(const std::string& title,
                             const std::string& img_path);
    
    void addButton(ToolBarButton& button);
    
    void addButton(ToolBarButton&& button);
    
    void removeButton(const std::string& name);
    
    std::optional<ToolBarButton> getButton(const std::string& title);
    
private:
    ViewStyle mViewStyle = ViewStyle::ICON;
    
    std::list<ToolBarButton> mButtons;
    
public:
    PROPERTY_CONST_GET(ViewStyle,mViewStyle);
    
    void setViewStyle(const ViewStyle& value);
};
}
}
