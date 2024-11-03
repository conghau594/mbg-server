#ifndef _MBG_ISERVER_STATE_H
#define _MBG_ISERVER_STATE_H

#include "interface/iState"

namespace mbg {
  class iServerState : public iState {
  public:
    virtual auto listenCommand() -> iServerState* = 0;
  }
}

#endif