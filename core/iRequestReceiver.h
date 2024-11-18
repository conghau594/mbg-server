//iRequestReceiver.h

#ifndef _MBG_I_RECEIVER_H
#define _MBG_I_RECEIVER_H

#include "String.h"

namespace mbg {
  class iRequestReceiver {
  public:
    virtual ~iRequestReceiver() = default;
    virtual void run() = 0;
    virtual void exit() = 0;
    virtual void receive(RawType data) = 0;
  };
} // namespace mbg

#endif // !_MBG_I_RECEIVER_H
