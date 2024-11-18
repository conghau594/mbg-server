//ServerStateBase.h

#ifndef _MBG_SERVER_STATE_BASE_H
#define _MBG_SERVER_STATE_BASE_H

#include "iServerState.h"
#include "ServerComponents.h"
#include <iostream>

namespace mbg {
  class ServerStateBase : public iServerState {
  protected:
    ServerComponents& serverComps_;

  public:
    ServerStateBase(ServerComponents& components) : serverComps_(components) {}
  protected:
    virtual void notifyEntering() = 0;
    virtual void notifyExiting() = 0;

  };

} // namespace mbg

#endif // !_MBG_SERVER_STATE_BASE_H