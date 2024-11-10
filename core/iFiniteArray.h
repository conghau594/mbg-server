//iFiniteArray.h
#ifndef _MBG_I_FINITE_ARRAY_H
#define _MBG_I_FINITE_ARRAY_H

#include "basetypes.h"
#include "iContainer.h"

namespace mbg {
  template <typename T>
  class iFiniteArray : public iContainer {
  public:
    virtual ~iFiniteArray() = default;
    virtual void pushBack(const T& value) = 0;
    virtual void popBack() = 0;
    virtual T& operator[](SizeType index) = 0;
    virtual const T& operator[](SizeType index) const = 0;
    virtual Bool isFull() = 0;
    virtual void collapse() = 0;
    virtual Bool getNumAvailableSlots() = 0;
    virtual void moveTo(iFiniteArray<T>& dest) = 0;
    virtual void moveTo(iFiniteArray<T>& dest, SizeType start, SizeType end, SizeType n) = 0;
    
  };
} // namespace mbg

#endif // !_MBG_I_FINITE_ARRAY_TMPL_H

