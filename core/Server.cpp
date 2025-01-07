//Server.cpp

#include "Server.h"

namespace mbg {
  void Server::run() {
    state_ = new ServerBeginning(components_);
    state_->onEnter();

    while (!shouldExit()) {
      ServerStateEnum newStateCmd = state_->listenCommand();
      iServerState* newState = nullptr;
      switch (newStateCmd)
      {   
      case SS_BEGINNING:
        break;

      case SS_RUNNING:
        newState = new ServerRunning(components_);
        break;

      case SS_REJECTING:
        break;

      case SS_PAUSING:
        break;

      case SS_ENDING:
        break;

      default: // case SERVER_STATE_INVALID:
        break;
      }

      if (newState == nullptr) {
        continue;
      }
      changeState(newState);
    }

    state_->onExit();
  }
} // namespace mbg