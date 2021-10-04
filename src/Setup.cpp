
#include "lightsky/script/Setup.h"
#include "lightsky/script/ScriptVariable.h"
#include "lightsky/script/ScriptFunctor.h"


#if !defined(_MSC_VER)

    #ifdef LS_HAVE_LS_POINTERS
        template class ls::utils::Pointer<ls::script::Variable, ls::utils::PointerDeleter<ls::script::Variable>>;
        template class ls::utils::Pointer<ls::script::Functor, ls::utils::PointerDeleter<ls::script::Functor>>;

    #else
        template class std::unique_ptr<ls::script::Variable, std::default_delete<ls::script::Variable>>;
        template class std::unique_ptr<ls::script::Functor, std::default_delete<ls::script::Functor>>;

    #endif /* LS_HAVE_LS_POINTERS */

#endif /* _MSC_VER */
