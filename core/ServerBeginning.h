//ServerBeginning.h

#ifndef _MBF_SERVER_BEGINNING_H
#define _MBF_SERVER_BEGINNING_H

#include "BaseServerState.h"
#include "iProcessor.h"

namespace mbg {
  class ServerBeginning : public BaseServerState {
  protected:
    virtual void notifyEntering() override { }
    virtual void notifyExiting() override {}

  public:
    //ServerBeginning()
    virtual void onEnter() override {}
    virtual void onExit() override {}



  };
} // namespace mbg

#endif // !_MBF_SERVER_BEGINNING_H
