//ServerComponents.h

#ifndef _MBG_SERVER_COMPONENTS_H
#define _MBG_SERVER_COMPONENTS_H

#include "iRequestMediator.h"
#include "iRequestReceiver.h"
#include "ClientNotifier.h"

namespace mbg {
  class ServerComponents {
  public:
    iRequestMediator* globalMediator_;
    iRequestReceiver* globalReceiver_;

    iRequestMediator* chessGameMediator_;
    iRequestReceiver* chessGameReceiver_;

    ClientNotifier* clientNotifier_;
  };
} // namespace mbg

#endif // !_MBG_SERVER_COMPONENTS_H
