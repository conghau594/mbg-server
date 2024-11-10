//Server.h

#ifndef _MBG_SERVER_H
#define _MBG_SERVER_H

#include "iServer.h"     
#include "iServerState.h"

namespace mbg {
  class Server : public iServer {
    iServerState* mState;
    bool          mShouldExit; 

  public:
    void run() override;  // TODO: Implement this in the Server class.
    void exit() override; // TODO: Implement this in the Server class.
    void changeState(iServerState* newState) { /* TODO: Implement this in the Server class */ }
  };
}

#endif