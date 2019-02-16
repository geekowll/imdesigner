#pragma once

#include "widget.hpp"

namespace st {
namespace ui {
class TextView : public Widget {
public:
    TextView() = default;
    virtual ~TextView() = default;
    
    explicit TextView(const std::string& name,
                      Widget* parent);
    
protected:
    void paint() final override;
    
private:
    SIGNAL(TextChanged,void,std::string);
    
    std::string mText;
public:
    template<typename ... Args>
    void setText( const std::string& format, Args ... args )
    {
        size_t size = snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
        std::unique_ptr<char[]> buf( new char[ size ] ); 
        snprintf( buf.get(), size, format.c_str(), args ... );
        mText = std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
    }
    
public:
    PROPERTY_CONST(Text,mText);
    CONNECT(TextChanged,mSigTextChanged,sigTextChanged_t)
};
} // namespace ui
} // namespace st
