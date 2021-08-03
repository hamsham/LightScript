
#include "lightsky/script/Setup.h"
#include "lightsky/script/ScriptVariable.h"
#include "lightsky/script/ScriptFunctor.h"


#if !defined(_MSC_VER)

//template class ls::utils::Pointer<ls::script::Variable>;
//template class ls::utils::Pointer<ls::script::Functor>;

template class std::unique_ptr<ls::script::Variable, std::default_delete<ls::script::Variable>>;
template class std::unique_ptr<ls::script::Functor, std::default_delete<ls::script::Functor>>;

#endif
