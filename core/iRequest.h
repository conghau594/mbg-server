//iRequest.h

#ifndef _MBG_I_REQUEST_H
#define _MBG_I_REQUEST_H

#include "basetypes.h"
#include "ExtendedType.h"

namespace mbg {
  class iRequest {
  public:
    virtual ~iRequest() = default;
    virtual void destroy() = 0;
    virtual void setPath(PathType path) = 0;
    virtual PathType shiftPathToNext(SizeType n) = 0;
    virtual void appendDestination(PathType dest, SizeType n) = 0;
  };
}

#endif