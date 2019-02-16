#pragma once

#include <memory>
#include <deque>
#include "imgui.h"

namespace st {
namespace ui {

class KeyHandler{
    enum class Key{
        Tab,
        LeftArrow,
        RightArrow,
        UpArrow,
        DownArrow,
        PageUp,
        PageDown,
        Home,
        End,
        Insert,
        Delete,
        Backspace,
        Space,
        Enter,
        Escape,
        CTRL_A,         // for text edit CTRL+A: select all
        CTRL_C,         // for text edit CTRL+C: copy
        CTRL_V,         // for text edit CTRL+V: paste
        CTRL_X,         // for text edit CTRL+X: cut
        CTRL_Y,         // for text edit CTRL+Y: redo
        CTRL_Z,
    };

    class KeyListener{
    public:
        KeyListener() = default;
        virtual ~KeyListener() = default;

        virtual void onKeyPressed(int key) = 0;
        virtual void onKeyRelease(int key) = 0;
        virtual void onKeyDown(int key) = 0;
        virtual void onSpecialPressed(int key) = 0;
    };

    void render(){
        auto downControl = [=]{
            for(auto i = 0; i < KEYSSIZE; ++i){
                if(ImGui::IsKeyDown(i)){
                    for(const auto &listener : mListeners){
                        listener->onKeyDown(i);
                    }
                }
            }
        };
        auto pressControl = [=]{
            for(auto i = 0; i < KEYSSIZE; ++i){
                if(ImGui::IsKeyPressed(i)){
                    for(const auto &listener : mListeners){
                        listener->onKeyPressed(i);
                    }
                }
            }
        };
        auto releaseControl = [=]{
            for(auto i = 0; i < KEYSSIZE; ++i){
                if(ImGui::IsKeyReleased(i)){
                    for(const auto &listener : mListeners){
                        listener->onKeyRelease(i);
                    }
                }
            }
        };

        auto specialControl = [=]{
            for(auto i = (int)ImGuiKey_Tab; i < ImGuiKey_COUNT; ++i){
                if(ImGui::IsKeyPressed(i)){
                    for(const auto &listener : mListeners){
                        listener->onKeyRelease(i);
                    }
                }
            }
        };

        downControl();
        pressControl();
        releaseControl();
        specialControl();
    }

    constexpr static int KEYSSIZE = IM_ARRAYSIZE(ImGui::GetIO().KeysDown);

    using key_listener_t = std::shared_ptr<KeyListener>;
    std::deque<key_listener_t> mListeners;
};
}
}
