//Server.h

#ifndef _MBG_SERVER_H
#define _MBG_SERVER_H

#include "iServer.h"     
#include "iServerState.h"

namespace mbg {
  class Server : public iServer {
    iServerState* state_;
    bool          shouldExit_; 

  public:
    void run() override;  // TODO: Implement this in the Server class.
    void exit() override; // TODO: Implement this in the Server class.
    void changeState(iServerState* newState) { /* TODO: Implement this in the Server class */ }
  };
} // namespace mbg

#endif // !_MBG_SERVER_H