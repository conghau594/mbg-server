//iCriticalFiniteArray.h
#ifndef _MBG_CRITICAL_FINITE_ARRAY_H
#define _MBG_CRITICAL_FINITE_ARRAY_H

#include "iRequest.h"
#include "iFiniteArray.h"
#include "iCriticalSectionController.h"

namespace mbg {
  template <typename T>
  class iCriticalFiniteArray : public iFiniteArray<T>, public iCriticalSectionController 
  { };

  extern template class iCriticalFiniteArray<iRequest*>;

  using iRequestQueue = iCriticalFiniteArray<iRequest*>;

} // namespace mbg

#endif // !_MBG_CRITICAL_FINITE_ARRAY_TMPL_H