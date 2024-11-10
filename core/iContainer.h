//iContainer.h

#ifndef _MBG_I_CONTAINER_H
#define _MBG_I_CONTAINER_H

#include "basetypes.h"

namespace mbg {
  class iContainer {
  public:
    virtual ~iContainer() = default;
    virtual SizeType getSize() = 0;
    virtual Bool isEmpty() = 0;
    virtual void clear() = 0;
  };
} // namespace mbg

#endif

