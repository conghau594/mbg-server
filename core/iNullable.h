// iNullable.h

#ifndef _MBG_I_NULLABLE_H
#define _MBG_I_NULLABLE_H

#include "basetypes.h"

namespace mbg {
  class iNullable {
  public:
    virtual ~iNullable() = default;
    virtual constexpr Bool isNull() const = 0;
  };
}

#endif