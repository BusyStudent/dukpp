#include <dukpp/runtime.hpp>
#include <dukpp/context.hpp>

int main(){
    Duk::Runtime runtime;
    auto ctxt = runtime.create();
    ctxt.eval("print('hello')");
}