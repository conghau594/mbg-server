//ExtendedType.inst.h

#ifndef _MBG_EXTENDED_TYPE_INST_H
#define _MBG_EXTENDED_TYPE_INST_H

#include "iNullable.h"
#include "primitives.h"
#include "String.h"

namespace mbg {
  /// @brief Template class that represents an extended type which can be nullable.
  /// @tparam T The type of the value to be stored.
  template <typename T>
  class ExtendedType : public iNullable {
  private:
    T          value_;  ///< The value to be stored.
    const Bool isNull_; ///< Flag that indicates if the value is null.

  public:
    /// @brief Default constructor that initializes the value to its default and sets the isNull flag to true.
    constexpr ExtendedType() : value_{}, isNull_(true) {}
    
    /// @brief Constructor that initializes the value to the given value and sets the isNull flag to false.
    /// @param value The value to be stored.
    constexpr ExtendedType(const T& value) : value_(value), isNull_(false) {}

    /// @brief Assignment operator that assigns the given value to the stored value.
    /// @param value The value to be assigned.
    /// @return A reference to the current object.
    ExtendedType& operator=(const T& value) {
      value_ = value;
      return *this;
    }

    /// @brief Assignment operator that assigns the value of another ExtendedType object to the current object.
    /// @param value The ExtendedType object whose value is to be assigned.
    /// @return A reference to the current object.
    ExtendedType& operator=(const ExtendedType& value) {
      value_ = value.getValue();
      return *this;
    }

    /// @brief Checks if the value is null.
    /// @return True if the value is null, otherwise false.
    constexpr Bool isNull() const override {
      return isNull_;
    }

    /// @brief Conversion operator to the stored value type.
    /// @return The stored value.
    operator T() const {
      return value_;
    }

    /// @brief Sets the stored value.
    /// @param value The value to be stored.
    void setValue(const T& value) {
      value_ = value;
    }

    /// @brief Gets the stored value.
    /// @return A reference to the stored value.
    T constexpr& getValue() {
      return value_;
    }

    /// @brief Gets the stored value.
    /// @return A constant reference to the stored value.
    T const& getValue() const {
      return value_;
    }
  };

  extern template class ExtendedType<Int>;    
  extern template class ExtendedType<Uint>;   
  extern template class ExtendedType<SizeType>;
  extern template class ExtendedType<String>;
  extern template class ExtendedType<Float>;  
  extern template class ExtendedType<Char>;   
  extern template class ExtendedType<char*>;  

  using ExInt   = ExtendedType<Int>;      ///< @brief Type alias for the extended integer type.
  using ExUint  = ExtendedType<Uint>;     ///< @brief Type alias for the extended unsigned integer type.
  using ExSize  = ExtendedType<SizeType>; ///< @brief Type alias for the extended size type.
  using ExFloat = ExtendedType<Float>;    ///< @brief Type alias for the extended float type.
  using ExStr   = ExtendedType<String>;   ///< @brief Type alias for the extended string type.
  using ExChar  = ExtendedType<Char>;     ///< @brief Type alias for the extended character type.

  using PathType = ExUint; ///< @brief Type alias for the path for traveling through processors or game move of a player.

  extern const ExInt    NULL_INT;    ///< @brief Constant that represents a null integer object.
  extern const ExSize   NULL_SIZE;   ///< @brief Constant that represents a null size object.
  extern const ExUint   NULL_UINT;   ///< @brief Constant that represents a null unsigned integer object.
  extern const ExFloat  NULL_FLOAT;  ///< @brief Constant that represents a null float object.
  extern const ExStr    NULL_STRING; ///< @brief Constant that represents a null string object.
  extern const ExChar   NULL_CHAR;   ///< @brief Constant that represents a null character object.
  extern const PathType NULL_PATH;   ///< @brief Constant that represents a null path object.

}   // namespace mbg

#endif  // !_MBG_EXTENDED_TYPE_INST_H
