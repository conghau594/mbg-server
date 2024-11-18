//Server.h

#ifndef _MBG_SERVER_H
#define _MBG_SERVER_H


#include "iServer.h"
#include "ServerComponents.h"
#include "ServerBeginning.h"
#include "ServerRunning.h"

namespace mbg {
  class Server : public iServer {
#define TEST
#ifdef TEST
  public:
#endif 
    iServerState*     state_;
    ServerComponents  components_;
    bool              shouldExit_; 

  public:

    void run() override;  // TODO: Implement this in the Server class.
    void exit() override { shouldExit_ = true; }
    void changeState(iServerState* newState) { 
      state_->onExit();
      state_ = newState;
      state_->onEnter();
    }

  private:
    Bool shouldExit() const { return shouldExit_; }
  };
} // namespace mbg

#endif // !_MBG_SERVER_H