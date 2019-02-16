#pragma once

#include <memory>
#include <deque>
#include "imgui.h"

namespace st {
namespace ui {

class MouseHandler{
    enum class Button{
        LEFT_BUTTON = 0,
        RIGHT_BUTTON = 1,
        MIDDLE_BUTTON = 2
    };

    class MouseListener{
    public:
        MouseListener() = default;
        virtual ~MouseListener() = default;

        virtual void onMouseClick(Button) = 0;
        virtual void onMouseRelease(Button) = 0;
        virtual void onMouseDragging(Button) = 0;
    };

    using mouse_listener_t = std::shared_ptr<MouseListener>;
    std::deque<mouse_listener_t> mListeners;

    void render(){
        auto clickControl = [=]{
            if(ImGui::IsMouseClicked(0))
                for(const auto &listener: mListeners)
                    listener->onMouseClick(Button::LEFT_BUTTON);

            if(ImGui::IsMouseClicked(1))
                for(const auto &listener: mListeners)
                    listener->onMouseClick(Button::RIGHT_BUTTON);

            if(ImGui::IsMouseClicked(2))
                for(const auto &listener: mListeners)
                    listener->onMouseClick(Button::MIDDLE_BUTTON);
        };

        auto releaseControl = [=]{
            if(ImGui::IsMouseReleased(0))
                for(const auto &listener: mListeners)
                    listener->onMouseRelease(Button::LEFT_BUTTON);

            if(ImGui::IsMouseReleased(1))
                for(const auto &listener: mListeners)
                    listener->onMouseRelease(Button::RIGHT_BUTTON);

            if(ImGui::IsMouseReleased(2))
                for(const auto &listener: mListeners)
                    listener->onMouseRelease(Button::MIDDLE_BUTTON);
        };

        auto draggingControl = [=]{
            if(ImGui::IsMouseDragging(0))
                for(const auto &listener: mListeners)
                    listener->onMouseDragging(Button::LEFT_BUTTON);

            if(ImGui::IsMouseDragging(1))
                for(const auto &listener: mListeners)
                    listener->onMouseDragging(Button::RIGHT_BUTTON);

            if(ImGui::IsMouseDragging(2))
                for(const auto &listener: mListeners)
                    listener->onMouseDragging(Button::MIDDLE_BUTTON);
        };

        clickControl();
        releaseControl();
        draggingControl();
    }
};
}
}
