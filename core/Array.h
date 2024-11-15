// Array.h
#ifndef _MBG_ARRAY_H
#define _MBG_ARRAY_H

#include <vector>


namespace mbg {
  template <typename T>
  using Array = std::vector<T>;  ///< Alias for std::vector.

} // namespace mbg

#endif // !_MBG_ARRAY_H
