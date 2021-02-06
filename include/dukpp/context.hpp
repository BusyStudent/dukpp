#if !defined(_DUKPP_CONTEXT_HPP_)
#define _DUKPP_CONTEXT_HPP_
#include <cstddef>
#include <string>
#include "defs.hpp"
namespace Duk{
    struct _nullopt_t{};
    constexpr auto nullopt = _nullopt_t{};
    class Value;
    class Runtime;
    /**
     * @brief Duktape context
     * 
     */
    class DUKPP_API Context{
        public:
            /**
             * @brief Construct a empty Context object
             * 
             */
            Context():ctxt(nullptr){}
            /**
             * @brief Construct a new Context object from Runtime
             * 
             * @param runtime The runtime
             */
            Context(Runtime &runtime);
            Context(const Context &) = delete;
            Context(Context &&c){
                ctxt = c.ctxt;
                c.ctxt = nullptr;
            }
            ~Context();
            /**
             * @brief Eval string
             * 
             * @param code the result
             * @return Value 
             */
            Value eval(const char *code);
            /**
             * @brief Get duktape context
             * 
             * @return _dukpp_context_t* 
             */
            _dukpp_context_t *get() const noexcept{
                return ctxt;
            }
            Context &operator =(Context &&ctxt);
        public:
            //memory resource
            void *alloc(size_t byte);
            void *realloc(void *ptr,size_t byte);
            void  free(void *ptr);
        private:
            Context(_dukpp_context_t *c):ctxt(c){};
            _dukpp_context_t *ctxt;
        friend class Runtime;
    };
    /**
     * @brief Value's data
     * 
     */
    union ValueData{
        double v_number;
        bool   v_bool;
        const char *v_string;
        const char *v_error;
    };
    class DUKPP_API Value{
        public:
            /**
             * @brief Construct a new Value object
             * @internal It is used by class Context
             * @param type 
             * @param data 
             */
            Value(int_t type,ValueData data){
                vtype = type;
                vdata = vdata;
            }
            void unwrap();
        private:
            ValueData vdata;
            int_t vtype;//< value's type
        friend class Context;
    };
}


#endif // _DUKPP_CONTEXT_HPP_
