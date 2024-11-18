//iInitializer.h

#ifndef _MBG_I_INITIALIZER_H
#define _MBG_I_INITIALIZER_H

namespace mbg {
  class iInitializer {
  public:
    virtual ~iInitializer() = default;
    virtual void execute() = 0;
  };
} // namespace mbg

#endif // !_MBG_I_INITIALIZER_H