//ServerBeginning.h

#ifndef _MBG_SERVER_BEGINNING_H
#define _MBG_SERVER_BEGINNING_H

#include "ServerStateBase.h"
#include "iRequestProcessor.h"

namespace mbg {
  class ServerBeginning : public ServerStateBase {
  protected:
    virtual void notifyEntering() override { }
    virtual void notifyExiting() override {}

  public:
    ServerBeginning() = default;
    virtual void onEnter() override {}
    virtual void onExit() override {}



  };
} // namespace mbg

#endif // !_MBG_SERVER_BEGINNING_H
