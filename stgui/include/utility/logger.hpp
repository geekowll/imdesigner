#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/ostream_sink.h>
#include <iostream>

namespace st::utility{

namespace  {
using namespace spdlog;

template <typename Arg1, typename... Args> 
void TRACE(const char* fmt, const Arg1& arg1, const Args&... args){ 
    spdlog::get("imlog")->trace(fmt,arg1,args...);
}

template <typename Arg1, typename... Args> 
void DEBUG(const char* fmt, const Arg1& arg1, const Args&... args){
    spdlog::get("imlog")->debug(fmt,arg1,args...);
}

template <typename Arg1, typename... Args> 
void INFO(const char* fmt, const Arg1& arg1, const Args&... args){
    spdlog::get("imlog")->info(fmt,arg1,args...);
}

template <typename Arg1, typename... Args> 
void WARN(const char* fmt, const Arg1& arg1, const Args&... args){
    spdlog::get("imlog")->warn(fmt,arg1,args...);
}
template <typename Arg1, typename... Args> 
void ERROR(const char* fmt, const Arg1& arg1, const Args&... args){
    spdlog::get("imlog")->error(fmt,arg1,args...);
}

template <typename Arg1, typename... Args> 
void CRITICAL(const char* fmt, const Arg1& arg1, const Args&... args){
    spdlog::get("imlog")->critical(fmt,arg1,args...);
}
} 


}
