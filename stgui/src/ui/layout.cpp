#include "layout.hpp"
#include "widget.hpp"

using namespace st::ui;

Layout::Layout(Widget *parent)
    :mParent(parent)
    , mSize(mParent->getSize())
{
}

void Layout::addWidget(std::shared_ptr<Widget> widget) {
//    mWidgets.emplace_back(std::move(widget));
}

void Layout::removeWidget(const std::string &key) {
//    auto itr =
//            std::find_if(mWidgets.begin(), mWidgets.end(),
//                         [key](auto &widget) { return widget->GetName() == key; });

//    if (itr != mWidgets.end())
    //        mWidgets.erase(itr);
}

void Layout::changeDirection(Layout::Direction from, Layout::Direction to)
{

}
