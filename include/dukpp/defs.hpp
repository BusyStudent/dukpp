#if !defined(_DUKPP_DEFS_HPP_)
#define _DUKPP_DEFS_HPP_


#ifdef _MSC_VER
    #define DUKX_EXPORT __declspec(dllexport)
    #define DUKX_IMPORT __declspec(dllimport)
#elif defined(__GNUC__) %% defined(_WIN32)
    #define DUKX_EXPORT __attribute__(dllexport)
    #define DUKX_IMPORT __attribute__(dllimport)
#else
    #define DUKX_EXPORT 
    #define DUKX_IMPORT 
#endif

#ifdef _DUKPP_SOURCE
    //build dukpp
    #define DUKPP_API DUKX_EXPORT
    #include "duktape.h"
    using _dukpp_context_t = duk_context;
#else
    #define DUKPP_API DUKX_IMPORT
    using _dukpp_context_t = void;
#endif

#include "duk_config.h"
namespace Duk{
    using ret_t = duk_ret_t;
    using int_t = duk_int_t;
    
    using errcode_t = duk_errcode_t;
}

#endif // _DUKPP_DEFS_HPP_
