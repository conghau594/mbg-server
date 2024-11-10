//ExtendedType.inst.h

#ifndef _MBG_EXTENDED_TYPE_INST_H
#define _MBG_EXTENDED_TYPE_INST_H

#include "iNullable.h"
#include "basetypes.h"

namespace mbg {
  template <typename T>
  class ExtendedType : public iNullable {
  private:
    T mValue;
    const Bool mIsNull;

  public:
    constexpr ExtendedType() : mValue{}, mIsNull(true) {}
    constexpr ExtendedType(const T& value) : mValue(value), mIsNull(false) {}

    constexpr Bool isNull() const override {
      return mIsNull;
    }

    void setValue(const T& value) {
      mValue = value;
    }

    T constexpr& getValue() {
      return mValue;
    }

    T const& getValue() const {
      return mValue;
    }
  };

  extern template class ExtendedType<Int>;
  extern template class ExtendedType<Uint>;
  extern template class ExtendedType<String>;
  extern template class ExtendedType<Float>;
  extern template class ExtendedType<Char>;

  using ExInt = ExtendedType<Int>;
  using ExUint = ExtendedType<Uint>;
  using ExFloat = ExtendedType<Float>;
  using ExStr = ExtendedType<String>;
  using ExChar = ExtendedType<Char>;

  using PathType = ExUint;
}

#endif
