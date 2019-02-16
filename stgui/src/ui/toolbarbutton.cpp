#include "toolbarbutton.hpp"

using namespace st::ui;

ToolBarButton::ToolBarButton(const std::string &name, const std::string &title)
    :Button(name,title)
{
    mSize = TOOLBAR_BUTTON_DEFAULT_SIZE;
}

ToolBarButton::ToolBarButton(const std::string &name)
    :ToolBarButton("##"+name,name)
{
}

ToolBarButton::ToolBarButton(const std::string& name,
                             const std::string& title,
                             const std::string& img_path)
    :Button(name,title,nullptr,img_path)
{   
    mSize = TOOLBAR_BUTTON_DEFAULT_SIZE;
}

