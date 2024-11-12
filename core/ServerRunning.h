//ServerRunning.h

#ifndef _MBG_SERVER_RUNNING_H
#define _MBG_SERVER_RUNNING_H

#include "BaseServerState.h"

namespace mbg {
  class ServerRunning : public BaseServerState {
  protected:
    virtual void notifyEntering() override { }
    virtual void notifyExiting() override {}

  public:
    //ServerRunning()
    virtual void onEnter() override {}
    virtual void onExit() override {}

  };
} // namespace mbg
#endif // !_MBG_SERVER_RUNNING_H

