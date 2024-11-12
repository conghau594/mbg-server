//CriticalFiniteArray.cpp 
#include "CriticalFiniteArray.h"

namespace mbg {
  
  template class iCriticalFiniteArray<iRequest*>;
  template class CriticalFiniteArray<iRequest*>;

  template class iCriticalFiniteArray<RawType>;
  template class CriticalFiniteArray<RawType>;



} // namespace mbg