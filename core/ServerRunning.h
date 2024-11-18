//ServerRunning.h

#ifndef _MBG_SERVER_RUNNING_H
#define _MBG_SERVER_RUNNING_H

#include "ServerStateBase.h"
#include "Thread.h"

namespace mbg {
  class ServerRunning : public ServerStateBase {
  public:
    ServerRunning(ServerComponents& components) : ServerStateBase(components) {}

    void onEnter() override {
      Thread chessGameMedThread(&iRequestMediator::run, serverComps_.chessGameMediator_);
      Thread chessGameRcvThread(&iRequestReceiver::run, serverComps_.chessGameReceiver_);
      
      chessGameMedThread.detach();
      chessGameRcvThread.detach();

      notifyEntering();
    }

    void onExit() override {}

    ServerStateEnum listenCommand() override {
      std::cout << "\nServer [Running] is listening for command: ";
      String command;
      std::cin >> command;
      if ((command == "reject") /*|| (std::stoi(command) == SV_STATE_REJECTING)*/) {
        return SV_STATE_REJECTING;
      }

      return SV_STATE_INVALID;
    }

  protected:
    void notifyEntering() override {
      std::cout << "\nServer is running...";
    }
    void notifyExiting() override {}

  };
} // namespace mbg
#endif // !_MBG_SERVER_RUNNING_H

