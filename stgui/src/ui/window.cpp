#include "window.hpp"
#include "layout.hpp"
#include "gridlayout.hpp"
#include "imgui_internal.h"
#include "logger.hpp"

using namespace st::ui;
using namespace st::utility;

/**
 * @brief Window::Window
 * @param name
 */
Window::Window(const std::string &name)
    : Widget(name,
             nullptr,
             ImGuiWindowFlags_NoMove |
             ImGuiWindowFlags_NoResize |
             ImGuiWindowFlags_NoCollapse |
             ImGuiWindowFlags_NoTitleBar)
{
    mLayout = std::make_shared<GridLayout>(this);
    
    setStyle(ImGuiStyleVar_WindowRounding,0.0f);
}

/**
 * @brief Window::paint
 */
void Window::paint()
{
    ImGui::SetNextWindowPos(getOffset(),ImGuiCond_Always);
    ImGui::SetNextWindowSize(mSize,ImGuiCond_Always);
    
    if(ImGui::Begin(mName.c_str(),&mVisible,mFlags)){
    }
    
    ImGui::End(); 
    
    if(mMenuBar)
        mMenuBar->draw();
    
    if(mToolBar && mToolBar->getVisible())
        mToolBar->draw();
   
    if(mStatusBar&& mToolBar->getVisible())
        mStatusBar->draw();
    
    update();
}

/**
 * @brief Window::update
 */
void Window::update(){
    
    auto width = ImGui::GetIO().DisplaySize.x;
    auto height = ImGui::GetIO().DisplaySize.y;
    
    setOffset({0,0});
    
    if(mMenuBar){
        ImGuiContext* g = ImGui::GetCurrentContext();
        mMenuBar->setSize(ImVec2{ mWidth, g->NextWindowData.MenuBarOffsetMinVal.y +
                                  g->FontBaseSize +
                                  g->Style.FramePadding.y +
                                  3*BAR_PADDING});
        
        height -= mMenuBar->getHeight();
        mOffset.y += mMenuBar->getHeight();
    }
    
    if(mToolBar){
        mToolBar->setOffset({0,  mMenuBar->getHeight()});
        mToolBar->setSize(ImVec2(mWidth,BAR_HEIGHT));
        
        height -= mToolBar->getHeight();
        mOffset.y += mToolBar->getHeight();
    }
    
    if(mStatusBar){
        height -= BAR_HEIGHT;
        
        mStatusBar->setOffset({0,ImGui::GetIO().DisplaySize.y - BAR_HEIGHT});
        mStatusBar->setSize(ImVec2(mWidth,BAR_HEIGHT));
        
    }
    
    setSize({width,height});
    mLayout->setSize({width,height});
}
