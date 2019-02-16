#pragma once

#include "widget.hpp"
#include "menu.hpp"

namespace st {
namespace ui {

class MenuBar : public Widget {
public:
    MenuBar(const std::string& name, Widget* parent);
    
    virtual ~MenuBar() = default;
    
    MenuBar(const MenuBar& other) = default;
    
    MenuBar(MenuBar&& other) = default;
    
    MenuBar& operator=(const MenuBar& other) = default;
    
    MenuBar& operator=(MenuBar&& other) = default;
    
    void paint() override;
    
    void addMenu(Menu const& menu);
    
    void addMenu(Menu&& menu);
    
    void removeMenu(Menu const& menu);
    
    void removeMenu(const std::string& title);
    
private:
    std::vector<Menu> mMenus;
};
} // namespace ui
} // namespace st
