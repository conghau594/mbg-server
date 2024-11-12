//iCriticalFiniteArray.h
#ifndef _MBG_I_CRITICAL_FINITE_ARRAY_H
#define _MBG_I_CRITICAL_FINITE_ARRAY_H

#include "iRequest.h"
#include "iFiniteArray.h"
#include "iCriticalArrayController.h"
#include "primitives.h"

namespace mbg {
  /**
   * @brief A template class that represents a critical finite array.
   * 
   * This class inherits from iFiniteArray<T> and iCriticalArrayController.
   * It provides functionalities of a finite array with critical section control.
   * 
   * @tparam T The type of elements stored in the array.
   */
  template <typename T>
  class iCriticalFiniteArray : public iFiniteArray<T>, public iCriticalArrayController
  { 
  public:
    virtual ~iCriticalFiniteArray() = default;
  };

  extern template class iCriticalFiniteArray<iRequest*>;
  extern template class iCriticalFiniteArray<RawType>;

  using iRequestQueue = iCriticalFiniteArray<iRequest*>;
  using iRawQueue = iCriticalFiniteArray<RawType>;      

} // namespace mbg

#endif // !_MBG_I_CRITICAL_FINITE_ARRAY_H