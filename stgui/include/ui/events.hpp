#pragma once

#include <string>
#include <functional>
#include <iostream>

namespace st{
namespace ui {

#define SIGNAL(Name,RT,...)  \
    using sig##Name##_t  = std::function<RT(__VA_ARGS__)>;    \
    sig##Name##_t mSig##Name;


#define CONNECT(Name,signal,slot)    \
    void bind##Name(slot s) {  \
    signal = s; \
}

#define TRIGGER(Name,signal,...)   \
    template <typename ...Ts>   \
    void emit##Name(Ts... args) {  \
        if(signal) signal(std::forward<Ts>(args)...);   \
        else std::cerr << "action not found" << std::endl; \
    }

using namespace std::placeholders;

template <typename Pred,typename ...Args>
static auto slot(Pred pred,Args... args){
    return std::bind(pred,std::forward<Args>(args)...);
}

// SLOT(&T::foo,ins,_1)
#define SLOT(...)   \
    slot(__VA_ARGS__);

class Event{
public:
};

#define EVENT(Name) \
    class Name##Event: public Event{    \
    public: \
};

#define EVENT_START(Name)    \
    class Name##Event: public Event {  \
    public:

#define EVENT_FINISH()    \
};

}
}


