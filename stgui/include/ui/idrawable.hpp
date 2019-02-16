#pragma once

namespace st::ui{
class IDrawable{
    virtual void paint() = 0;
    virtual void draw() = 0;
};
}
