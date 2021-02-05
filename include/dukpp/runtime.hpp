#if !defined(_DUKPP_RUNTIME_HPP_)
#define _DUKPP_RUNTIME_HPP_
#include <memory_resource>
#include "defs.hpp"
namespace Duk{
    class Context;
    class DUKPP_API Runtime{
        public:
            Runtime();
            Runtime(const Runtime &) = delete;
            ~Runtime();
            /**
             * @brief Create a context
             * 
             * @return Context 
             */
            Context create();
        private:
            std::pmr::memory_resource *alloc;
        friend class Context;
    };
}


#endif // _DUKPP_RUNTIME_HPP_
