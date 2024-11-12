//Function.h

#ifndef _MBG_FUNCTION_H
#define _MBG_FUNCTION_H

#include <functional>

namespace mbg {
  template <typename... ARGS>
  using Function = std::function<ARGS...>;
} // namespace mbg 

#endif // !_MBG_FUNCTION_H
