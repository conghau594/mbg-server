//Utility.h

#ifndef _MBG_UTILITY_H
#define _MBG_UTILITY_H

#include "primitives.h"
#include <cstring>
#include <cassert>

namespace mbg {
  /**
   * @brief A utility class that provides functionalities for the project.
   */
  class Utility final {
  public:
    static void copyMemory(void* dest, const void* src, SizeType size) {
      std::memcpy(dest, src, size);
    }
  };

} // namespace mbg

#endif // !_MBG_UTILITY_H
