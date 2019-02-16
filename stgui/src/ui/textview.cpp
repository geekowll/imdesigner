#include "textview.hpp"

using namespace st::ui;

TextView::TextView(const std::string &name, Widget *parent)
    : Widget(name,parent)
{
    setColor(ImGuiCol_Text,ImVec4(0.0f,0.0f,0.0f,1.0f));
}

void TextView::paint()
{
    ImGui::Text(mText.data());
}
