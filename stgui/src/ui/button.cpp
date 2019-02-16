#include "button.hpp"
#include "texhandler.hpp"
#include "logger.hpp"

using namespace st::ui; 
using namespace st::utility;

/**
 * @brief Button::Button
 * @param name
 * @param title
 * @param parent
 */
Button::Button(const std::string &name, 
               const std::string &title, 
               Widget *parent)
    :Widget(name,parent)
    , mTitle(title)
{
    setViewStyle(ViewStyle::TEXT);
}

/**
 * @brief Button::Button
 * @param name
 * @param title
 * @param parent
 * @param img_path
 */
Button::Button(const std::string &name,
               const std::string &title, 
               Widget *parent, 
               const std::string &img_path)
    : Button(name,title,parent)
{
    setViewStyle(ViewStyle::ICON);
    
    if(!img_path.empty())
        mTexId = TexHandler::load(img_path);    
}

/**
 * @brief Button::Button
 * @param name
 * @param title
 */
Button::Button(const std::string &name, const std::string &title)
    : Widget(name,nullptr)
    , mTitle(title)
{
}

/**
 * @brief Button::paint
 */
void Button::paint() {
    auto textPaint = [&]{
        ImGui::Button(mTitle.c_str(),mSize);
    };
    auto iconPaint = [&]{
        ImGui::ImageButton(mTexId,mSize,{0,0},{1,1});
    };
    
    switch(mViewStyle){
    case ViewStyle::TEXT:
        textPaint(); 
        break;
    case ViewStyle::ICON:
        iconPaint();
        break;
    default:
        break;
    }
}
