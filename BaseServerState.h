#ifndef _MBG_BASE_SERVER_STATE_H
#define _MBG_BASE_SERVER_STATE_H

#include "interface/iServerState"


namespace mbg {
  class BaseServerState : public iServerState {
  public:
    auto listenCommand() -> iServerState* override;

  protected:
    virtual void notifyEntering() = 0;
    virtual void notifyExiting() = 0;
  }
}

#endif