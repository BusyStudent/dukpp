#include "./build.hpp"

#include <dukpp/runtime.hpp>
#include <dukpp/context.hpp>
#include <dukpp/duktape.h>
namespace Duk{
    Runtime::Runtime(){
        alloc = new std::pmr::synchronized_pool_resource;
    }
    Runtime::~Runtime(){
        delete alloc;
    }
    Context Runtime::create(){
        auto allocate = [](){

        };
        auto deallocate = [](){

        };
        auto fatal = [](){

        };
        duk_context *ctxt = duk_create_heap(

        );
    }
}