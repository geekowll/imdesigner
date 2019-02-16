#pragma once

#include <string>
#include <vector>
#include "menuitem.hpp"
#include "idrawable.hpp"

namespace st {
namespace ui {

class MenuBar;

class Menu final: public IDrawable{
    friend class MenuBar;
    
public:
    explicit Menu(const std::string& title)
        :mTitle(title){}
    
    virtual ~Menu() = default;
    
    Menu(const Menu& other) = default;
    
    Menu(Menu&& other)= default; 
    
    Menu& operator=(const Menu& other)= default;
    
    Menu& operator=(Menu&& other)= default;
    
    void addMenuItem(MenuItem&& item);
    
    void addMenuItem(const MenuItem& item);
    
    void draw() final override;
    
protected:
    void paint() final override;
    
private:
    std::string mTitle;
    std::vector<MenuItem> mMenuItems;
};
}
}
