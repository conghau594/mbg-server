// iNullable.h

#ifndef _MBG_I_NULLABLE_H
#define _MBG_I_NULLABLE_H

#include "primitives.h"

namespace mbg {
  /**
   * @brief Interface for nullable objects.
   *
   * This class provides an interface for objects that can be null.
   * Derived classes must implement the isNull method to specify
   * the logic for determining if the object is null.
   */
  class iNullable {
  public:
    virtual ~iNullable() = default;

    /**
     * @brief Checks if the object is null.
     * 
     * This pure virtual function must be overridden by derived classes
     * to provide the logic for determining if the object is null.
     * 
     * @return constexpr Bool True if the object is null, otherwise false.
     */
    virtual constexpr Bool isNull() const = 0;
  }; 
} // namespace mbg

#endif // !_MBG_I_NULLABLE_H