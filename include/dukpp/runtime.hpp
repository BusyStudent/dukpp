#if !defined(_DUKPP_RUNTIME_HPP_)
#define _DUKPP_RUNTIME_HPP_
#include "defs.hpp"
namespace Duk{
    class Context;
    class DUKPP_API Runtime{
        public:
            Runtime();
            Runtime(const Runtime &) = delete;
            virtual ~Runtime();
            /**
             * @brief Create a context
             * 
             * @return Context 
             */
            Context create();
        public:
            /**
             * @brief Alloc memory
             * 
             * @param byte 
             * @return void* 
             */
            virtual void *alloc(size_t byte);
            virtual void *realloc(void *ptr,size_t byte);
            virtual void  free(void *ptr);
            virtual void  fatal(const char *msg);

        friend class Context;
    };
}


#endif // _DUKPP_RUNTIME_HPP_
