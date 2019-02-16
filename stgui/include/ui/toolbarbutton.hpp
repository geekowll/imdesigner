#pragma once

#include "button.hpp"

namespace st{
namespace ui{

class ToolBarButton final: public Button {
public:
    ToolBarButton() = default;
    
    virtual ~ToolBarButton() = default;
    
    explicit ToolBarButton(const std::string& name);
    
    explicit ToolBarButton(const std::string& name,
                           const std::string& title);
    
    explicit ToolBarButton(const std::string& name,
                    const std::string& title,
                    const std::string& img_path);
    
    ToolBarButton(const ToolBarButton& ) = default;
    ToolBarButton(ToolBarButton&& ) = default;
    ToolBarButton& operator=(const ToolBarButton&) = default;
    ToolBarButton& operator=(ToolBarButton&&) = default;
    
};
}
}
