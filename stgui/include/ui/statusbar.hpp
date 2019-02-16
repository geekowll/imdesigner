#pragma once

#include "widget.hpp"
#include "textview.hpp"

namespace st {
namespace ui {

class StatusBar final: public Widget{
public:
    StatusBar() = default;
    
    explicit StatusBar(const std::string& name,
                        Widget* parent);

    virtual ~StatusBar() = default;
   
protected:
    void paint() override;
    
private:
    std::string mStatusText;
    TextView mTextView;
    
public:
    PROPERTY_CONST(StatusText,mStatusText);
    
};
}
}
