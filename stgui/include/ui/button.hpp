#pragma once

#include "widget.hpp"

namespace st {
namespace ui {

class ToolBar;

class Button : public Widget {
public:
    Button() = default;
    virtual ~Button() = default;
    
    explicit Button(const std::string& name,
                    const std::string& title,
                    Widget* parent);
    
    explicit Button(const std::string& name,
                    const std::string& title,
                    Widget* parent,
                    const std::string& img_path);
    
    explicit Button(const std::string& name,
                    const std::string& title);
    
    Button(const Button& other) = default;
    
    Button(Button&& other) = default;
    
    Button& operator=(const Button& other) = default;
    
    Button& operator=(Button&& other) = default;
    
protected:
    void paint() final override;
    
protected:
    ViewStyle mViewStyle = ViewStyle::TEXT;
    ImTextureID mTexId = nullptr;
    std::string mTitle;
    
    SIGNAL(Clicked,void,void);
    
    PROPERTY_CONST_SET(ViewStyle,mViewStyle);
    
    friend class ToolBar;
    
public:
    PROPERTY_CONST_GET(TextureID,mTexId);
    
    CONNECT(Clicked,mSigClicked,sigClicked_t)
    TRIGGER(Clicked,mSigClicked,void)
};
} // namespace ui
} // namespace st
