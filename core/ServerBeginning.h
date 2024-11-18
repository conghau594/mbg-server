//ServerBeginning.h

#ifndef _MBG_SERVER_BEGINNING_H
#define _MBG_SERVER_BEGINNING_H

#include "ServerStateBase.h"
#include "iRequestProcessor.h"

#include "Initializer241111.h"

namespace mbg {
  class ServerBeginning : public ServerStateBase {
  public:
    ServerBeginning(ServerComponents& components) : ServerStateBase(components) {}
    
    void onEnter() override {
      Initializer241111(serverComps_).execute();
      notifyEntering();
    }
    void onExit() override {}

    ServerStateEnum listenCommand() override {
      std::cout << "\nServer [Beginning] is listening for command: ";
      String command;
      std::cin >> command;
      if ( (command == "start") /*|| (std::stoi(command) == SV_STATE_RUNNING)*/ ) {
        return SV_STATE_RUNNING;
      }

      return SV_STATE_INVALID;
    }

  protected:
    void notifyEntering() override {
      std::cout << "\nServer is beginning...";
    }
    void notifyExiting() override { }
  };
} // namespace mbg

#endif // !_MBG_SERVER_BEGINNING_H
