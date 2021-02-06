#include "./build.hpp"

#include <dukpp/context.hpp>
#include <dukpp/runtime.hpp>

namespace Duk{
    Context::~Context(){
        duk_destroy_heap(ctxt);
    }
    Context &Context::operator =(Context &&c){
        if(&c != this){
            duk_destroy_heap(ctxt);
            ctxt = c.ctxt;
            c.ctxt = nullptr;
        }
        return *this;
    }
    Value Context::eval(const char *code){
        duk_push_string(ctxt,code);
        auto ret = duk_peval(ctxt);
        if(ret != 0){
            
        }


        auto type = duk_get_type(ctxt,-1);
        ValueData data;
        switch(type){
            case DUK_TYPE_BOOLEAN:
                data.v_bool = duk_get_boolean(ctxt,-1);
                break;
            case DUK_TYPE_NUMBER:
                data.v_number = duk_get_number(ctxt,-1);
                break;
            case DUK_TYPE_NONE:
                //error
                
                break;
            default:
                break;
        }
        Value v(type,data);
        //reset the stack
        duk_pop(ctxt);
        return v;
    }


    void *Context::alloc(size_t byte){
        return duk_alloc(ctxt,byte);
    }
    void *Context::realloc(void *ptr,size_t byte){
        return duk_realloc(ctxt,ptr,byte);
    }
    void  Context::free(void *ptr){
        return duk_free(ctxt,ptr);
    }
}