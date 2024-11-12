// BaseServerState.h

#ifndef _MBG_BASE_SERVER_STATE_H
#define _MBG_BASE_SERVER_STATE_H

#include "iServerState.h" 

namespace mbg {
  class BaseServerState : public iServerState {
  public:
    iServerState* listenCommand() override { return nullptr; }
  protected:
    virtual void notifyEntering() = 0;
    virtual void notifyExiting() = 0;

  };
} // namespace mbg

#endif // !_MBG_BASE_SERVER_STATE_H