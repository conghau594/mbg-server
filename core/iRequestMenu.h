//iRequestMenu.h

#ifndef _MBG_I_REQUEST_MENU_H
#define _MBG_I_REQUEST_MENU_H

#include "ExtendedType.h"

namespace mbg {
  class iRequestMenu {
  public:
    virtual ~iRequestMenu() = default;
    virtual SizeType addPath(PathType path) = 0;
    virtual PathType getPath(ExInt index) const = 0;
  };
} // namespace mbg

#endif // !_MBG_I_REQUEST_MENU_H