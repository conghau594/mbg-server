// ExtendedType.tmpl.h

#ifndef _MBG_EXTENDED_TYPE_H
#define _MBG_EXTENDED_TYPE_H

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
}

#endif
