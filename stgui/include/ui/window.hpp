#pragma once

#include "widget.hpp"
#include "menubar.hpp"
#include "toolbar.hpp"
#include "statusbar.hpp"

namespace st::ui {

class Window final: public Widget{
public:
    Window() = default;

    explicit Window(const std::string& name);

protected:
    void paint() override;

private:
    std::unique_ptr<ToolBar> mToolBar;
    std::unique_ptr<StatusBar> mStatusBar;
    std::unique_ptr<MenuBar> mMenuBar;

public:
    PROPERTY_MOVE_SET(ToolBar,mToolBar)
    PROPERTY_MOVE_SET(StatusBar,mStatusBar)
    PROPERTY_MOVE_SET(MenuBar,mMenuBar);

private:
    void update();
};

}
