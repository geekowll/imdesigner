#include "statusbar.hpp"
#include "logger.hpp"

using namespace st::utility;
using namespace st::ui;

StatusBar::StatusBar(const std::string &name, Widget *parent)
    :Widget(name,parent)
    , mTextView("##statusText",this)
{
    setStyle(ImGuiStyleVar_WindowPadding,ImVec2(10.0f,8.0f));
    setStyle(ImGuiStyleVar_WindowRounding,0.0f);
    setColor(ImGuiCol_WindowBg,ImVec4(1.0f,1.0f,1.0f,1.0f));
    
    mTextView.setColor(ImGuiCol_Text,ImVec4{0.0f,0.0f,0.0f,1.0f});
    mStatusText = "StatusBar";
}

void StatusBar::paint()
{
    ImGui::SetNextWindowPos(mOffset);
    ImGui::SetNextWindowSize(mSize,ImGuiCond_Always);
    
    if(ImGui::Begin(mName.c_str(),&mVisible,
                    ImGuiWindowFlags_NoMove |
                    ImGuiWindowFlags_NoScrollbar |
                    ImGuiWindowFlags_NoNav |
                    ImGuiWindowFlags_NoResize |
                    ImGuiWindowFlags_NoCollapse |
                    ImGuiWindowFlags_NoTitleBar)){
        mTextView.setText(mStatusText);
        mTextView.draw();
    }
    
    ImGui::End();
}
