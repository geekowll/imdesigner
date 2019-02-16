#include "menubar.hpp"
#include "toolkit.hpp"
#include "imgui.h"

using namespace st::ui;

/**
 * @brief MenuBar::MenuBar
 * @param name
 * @param parent
 */
MenuBar::MenuBar(const std::string &name, Widget *parent)
    :Widget(name,parent){
}

/**
 * @brief MenuBar::paint
 */
void MenuBar::paint()
{
    if (ImGui::BeginMainMenuBar())
    {
        for(auto& menu: mMenus)
            menu.paint();
        
        ImGui::EndMainMenuBar();
    }
}

/**
 * @brief MenuBar::addMenu
 * @param menu
 */
void MenuBar::addMenu(const Menu &menu) { mMenus.emplace_back(menu); }

/**
 * @brief MenuBar::addMenu
 * @param menu
 */
void MenuBar::addMenu(Menu &&menu) { mMenus.emplace_back(std::move(menu)); }

/**
 * @brief MenuBar::removeMenu
 * @param menu
 */
void MenuBar::removeMenu(const Menu &menu){
    mMenus.erase(std::remove_if(mMenus.begin(),
                                mMenus.end(),
                                [menu](const Menu& val){ return menu.mTitle == val.mTitle; }),
                 mMenus.end());
    
}

/**
 * @brief MenuBar::removeMenu
 * @param title
 */
void MenuBar::removeMenu(const std::string &title){
    mMenus.erase(std::remove_if(mMenus.begin(),
                                mMenus.end(),
                                [title](const Menu& val){ return title == val.mTitle; }),
                 mMenus.end());
    
}
