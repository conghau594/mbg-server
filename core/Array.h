// Array.h
#ifndef _MBG_ARRAY_H
#define _MBG_ARRAY_H

#include <vector>
#include "iProcessor.h"


namespace mbg {
  template <typename T>
  using Array = std::vector<T>;  ///< Alias for std::vector.

  extern template Array<iProcessor*>;

  using ProcessorList = Array<iProcessor*>;  ///< Alias for a vector of processors.
} // namespace mbg

#endif // !_MBG_ARRAY_H
