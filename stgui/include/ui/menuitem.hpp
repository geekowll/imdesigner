#pragma once

#include <string>
#include "events.hpp"

namespace st {
namespace ui {

class Menu;

class MenuItem{
    friend class Menu;
    
public:
    explicit MenuItem(const std::string& title)
        :mTitle(title)
    {}
    
    MenuItem(const MenuItem& other) = default;
    
    MenuItem(MenuItem&& other) = default;
    
    MenuItem& operator=(const MenuItem& other) = default;
    
    MenuItem& operator=(MenuItem&& other) = default;
    
private:
    std::string mTitle;
    SIGNAL(Clicked,void,void);
    
public:
    CONNECT(Clicked,mSigClicked,sigClicked_t)
    TRIGGER(Clicked,mSigClicked,void);
        
};
}
}
