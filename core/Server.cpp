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
      case SV_STATE_BEGINNING:
        break;

      case SV_STATE_RUNNING:
        newState = new ServerRunning(components_);
        break;

      case SV_STATE_REJECTING:
        break;

      case SV_STATE_PAUSING:
        break;

      case SV_STATE_ENDING:
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