#include "toolbar.hpp"
#include "logger.hpp"

using namespace st::ui;
using namespace st::utility;

ToolBar::ToolBar(const std::string &name, Widget *parent)
    :Widget(name,parent)
{
    setSize(ImVec2{BAR_WIDTH,BAR_HEIGHT});
    setViewStyle(ViewStyle::TEXT);
    
    setStyle(ImGuiStyleVar_WindowPadding,ImVec2(10.0f,5.0f));
    setStyle(ImGuiStyleVar_WindowRounding,0.0f);
    setColor(ImGuiCol_WindowBg,ImVec4(1.0f,1.0f,1.0f,1.0f));
}

void ToolBar::paint()
{
    ImGui::SetNextWindowPos(mOffset,ImGuiCond_Always);
    ImGui::SetNextWindowSize(mSize,ImGuiCond_Always);
    
    ImGui::Begin(mName.c_str(),&mVisible,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoScrollbar |
                 ImGuiWindowFlags_NoNav |
                 ImGuiWindowFlags_NoResize |
                 ImGuiWindowFlags_NoCollapse |
                 ImGuiWindowFlags_NoTitleBar);
    
    for(auto& button: mButtons){
        button.draw();
        ImGui::SameLine();
    }
    
    ImGui::End();
}

/**
 * @brief ToolBar::addButton
 * @param title
 * @return 
 */
ToolBarButton& ToolBar::addButton(const std::string &title)
{
    ToolBarButton button(
                "##" + title,
                title,
                "");
    button.setViewStyle(getViewStyle());
    mButtons.emplace_back(std::move(button));
    
    return mButtons.back();
}

/**
 * @brief ToolBar::addButton
 * @param title
 * @param img_path
 * @return 
 */
ToolBarButton& ToolBar::addButton(const std::string &title, 
                                  const std::string &img_path)
{
    ToolBarButton button(
                "##" + title,
                title,
                img_path);
    button.setViewStyle(getViewStyle());
    mButtons.emplace_back(std::move(button));
    
    return mButtons.back();
}

/**
 * @brief ToolBar::addButton
 * @param button
 */
void ToolBar::addButton(ToolBarButton& button)
{
    button.setViewStyle(getViewStyle());
    mButtons.emplace_back(button);
}

/**
 * @brief ToolBar::addButton
 * @param button
 */
void ToolBar::addButton(ToolBarButton &&button)
{
    button.setViewStyle(getViewStyle());
    mButtons.emplace_back(std::move(button));
}

/**
 * @brief ToolBar::removeButton
 * @param name
 */
void ToolBar::removeButton(const std::string &name)
{
    mButtons.remove_if([&](const ToolBarButton& button){
        return button.getName() == name;});
}

/**
 * @brief ToolBar::getButton
 * @param title
 * @return 
 */
std::optional<ToolBarButton> ToolBar::getButton(const std::string &title) {
    if(auto itr = std::find_if(mButtons.begin(),
                               mButtons.end(),
                               [title](const ToolBarButton& button){
                               return button.mTitle == title; });
            itr != mButtons.end()){
        return std::make_optional(*itr);
    }else
        return std::nullopt;
}

/**
 * @brief ToolBar::setViewStyle
 * @param value
 */
void ToolBar::setViewStyle(const ViewStyle &value)
{
    mViewStyle = value;
    
    for(auto& button: mButtons)
        button.setViewStyle(value);
}
