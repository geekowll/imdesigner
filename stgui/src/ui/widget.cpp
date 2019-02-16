#include "widget.hpp"
#include "layout.hpp"

using namespace st::ui;

/**
 * @brief Widget::Widget
 * @param name
 * @param parent
 * @param size
 * @param border
 * @param flags
 */
Widget::Widget(const std::string &name, Widget *parent, ImGuiWindowFlags flags)
    : mName(name)
    , mFlags(flags)
{
    setParent(parent);

    setColor(ImGuiCol_WindowBg,BG_COLOR);
    setColor(ImGuiCol_ChildBg,BG_COLOR);
    setColor(ImGuiCol_ChildWindowBg,BG_COLOR);
    setColor(ImGuiCol_FrameBg,BG_COLOR);
    setColor(ImGuiCol_PopupBg,BG_COLOR);
    
}

Widget::~Widget(){
    if(mChildren.size() > 0){
        mChildren.erase(std::remove_if(mChildren.begin(),
                                       mChildren.end(),
                                       [](Widget*){ return true;}),
                mChildren.end());
    }
}

/**
 * @brief Widget::operator ==
 * @param other
 * @return
 */
inline
bool Widget::operator==(const Widget &other){ 
    return mName == other.mName; 
}

void Widget::draw() {
    auto styleCount = 0, colorCount = 0;
    
    for(const auto &[key,value]: mColorMap){
        ImGui::PushStyleColor(key,value);
        colorCount++;
    }
    
    for(const auto &[key,value]: mStyleMap){
        VARIANT_TO_PUSHSTYLEVAR(value);
        styleCount++;
    }
    
    paint();
    
    ImGui::PopStyleVar( styleCount);
    ImGui::PopStyleColor( colorCount);    
}
/**
 * @brief Widget::paint
 */
void Widget::paint() {
   
}

/**
 * @brief Widget::setSizeMinMax
 * @param min
 * @param max
 */
inline
void Widget::setSizeMinMax(const ImVec2 &min, const ImVec2 &max) { mSizeMinMax = { min, max}; }

/**
 * @brief Widget::setParent
 * @param parent
 */
void Widget::setParent(Widget *parent){
    if(parent != nullptr){
        mParent = parent;            
        mParent->addChild(this);
    }
}

/**
 * @brief Widget::removeChild
 * @param child
 */
void Widget::removeChild(Widget *child) {
    
    auto [has,itr] = hasChild(child->getName());
            if(itr != mChildren.end())
            mChildren.erase(itr);
}
            
            /**
         * @brief Widget::hasChild
         * @param name
         * @return
         */
            std::pair<bool, Widget::iterator> Widget::hasChild(const std::string &name) {
        auto itr = std::find_if(mChildren.begin(),
                                mChildren.end(),
                                [name](Widget* value){ return name == value->getName(); });
        
        bool has = itr == mChildren.end();
        
        return {has,itr};
    }
    
    /**
 * @brief Widget::hasChild
 * @param name
 * @return
 */
    std::pair<bool, Widget::const_iterator> Widget::hasChild(const std::string &name) const{
        auto itr = std::find_if(mChildren.cbegin(),
                                mChildren.cbegin(),
                                [name](Widget* value){ return name == value->getName(); });
        
        bool has = itr == mChildren.end();
        
        return {has,itr};
    }
    
    
