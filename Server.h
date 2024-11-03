#ifndef _MBG_SERVER_H
#define _MBG_SERVER_H

#include "interface/iServer"
#include "interface/iServerState"

namespace mbg {
  class Server : public iServer {
    iServerState* mState;
    Bool          mShouldExit;
  public:
    void run() override;
    void exit() override;

  private:
    void initialize();
    auto shouldExit() -> Bool { return mShouldExit; }
    void changeState(iServerState* newState) { };
  }
}

#endif