// iServerState.h

#ifndef _MBG_I_SERVER_STATE_H
#define _MBG_I_SERVER_STATE_H

#include "iState.h"
#include "iServer.h"

namespace mbg {
  class iServerState : public iState, public iServer {
  public:
    virtual iServerState* listenCommand() = 0;
  };
} // namespace mbg

#endif // !_MBG_I_SERVER_STATE_H