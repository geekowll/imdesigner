#pragma once

#include "widget.hpp"

namespace st {
namespace ui {
class TreeView : public Widget {
public:
    TreeView() = default;
    virtual ~TreeView() = default;

    class TreeNode{
    public:
    };

    SIGNAL(SelectionChanged,void,TreeNode)
    CONNECT(SelectionChanged,mSigSelectionChanged,sigSelectionChanged_t)

    SIGNAL(NodeClicked,void,TreeNode)
    CONNECT(NodeClicked,mSigNodeClicked,sigNodeClicked_t)
};
} // namespace ui
} // namespace st
