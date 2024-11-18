//RequestMenu.h

#ifndef _MBG_REQUEST_MENU_H
#define _MBG_REQUEST_MENU_H

#include "iRequestMenu.h"
#include "Array.h"

namespace mbg {
  extern template Array<PathType>;

  class RequestMenu final : public iRequestMenu {
  private:
    Array<PathType> paths_;
  public:
    RequestMenu() = default;

    SizeType addPath(PathType path) override {
      paths_.emplace_back(path);
      return paths_.size() - 1;
    }

    PathType getPath(ExInt index) const override {
      if (index.isNull() or index >= paths_.size())
        return NULL_PATH;

      return paths_[index];
    }
  };
} // namespace mbg

#endif // !_MBG_REQUEST_MENU_H