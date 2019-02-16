#include "menu.hpp"
#include "imgui.h"
#include <iostream>

using namespace st::ui;

void Menu::addMenuItem(MenuItem &&item) {  
    mMenuItems.emplace_back(std::move(item)); 
}

void Menu::addMenuItem(const MenuItem &item) {  
    mMenuItems.emplace_back(item); 
}

void Menu::draw(){
    paint();
}

void Menu::paint(){
    if (ImGui::BeginMenu(mTitle.c_str()))
    {
        for(auto& item: mMenuItems){
            if(ImGui::MenuItem(item.mTitle.c_str()))
                item.emitClicked();

            ImGui::Separator();
        }

        ImGui::EndMenu();
    }
}
