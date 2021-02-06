#include "./build.hpp"

#include <dukpp/runtime.hpp>
#include <dukpp/context.hpp>
#include <dukpp/duktape.h>
#include <stdexcept>
#include <cstdlib>
#include <cstdio>
namespace Duk{
    Runtime::Runtime(){

    }
    Runtime::~Runtime(){

    }
    Context Runtime::create(){
        return Context(*this);
    }
    Context::Context(Runtime &rt){
        auto allocate = [](void *rt,duk_size_t size){
            return static_cast<Runtime*>(rt)->alloc(size);
        };
        auto deallocate = [](void *rt,void *ptr){
            if(ptr == nullptr){
                return;
            }
            static_cast<Runtime*>(rt)->free(ptr);
        };
        auto realloc = [](void *rt,void *ptr,duk_size_t byte){
            return static_cast<Runtime*>(rt)->realloc(ptr,byte);
        };
        auto fatal = [](void *rt,const char *msg){
            return static_cast<Runtime*>(rt)->fatal(msg);
        };
        ctxt = duk_create_heap(
            allocate,
            realloc,
            deallocate,
            &rt,
            fatal
        );
    }
}

namespace Duk{
    //basic memory from cstdlib
    void *Runtime::alloc(size_t byte){
        return std::malloc(byte);
    }
    void *Runtime::realloc(void *ptr,size_t byte){
        return std::realloc(ptr,byte);
    }
    void  Runtime::free(void *ptr){
        return std::free(ptr);
    }
    void  Runtime::fatal(const char *msg){
        fprintf(stderr,"Fatal in context %p:%s",this,msg);
        throw std::runtime_error(msg);
    }
}