//Initializer2411.h

#ifndef _MBG_INITIALIZER_241117_H
#define _MBG_INITIALIZER_241117_H


#include "iInitializer.h"
#include "ClientNotifier.h"
#include "RequestBus.h"
#include "RequestMenu.h"

#include "RequestMediator.h"
#include "RequestReceiver.h"


namespace mbg {
  class Initializer241111 : public iInitializer {
    ServerComponents& serverComps_;
  public:
    Initializer241111(ServerComponents& components) : serverComps_(components) {}

    void execute() override {
      serverComps_.clientNotifier_ = new ClientNotifier();
      iRequestBus* chessGameRqtBus = new RequestBus(NUM_BITS_FOR_REQUEST_TYPE);

      SizeType clientNotifierID = chessGameRqtBus->subscribe(serverComps_.clientNotifier_);
      SizeType clientNotifierPath = clientNotifierID;

      iRequestMenu* chessGameRqtMenu = new RequestMenu();
      SizeType idxClientNotifier = chessGameRqtMenu->addPath(clientNotifierPath);

      serverComps_.chessGameMediator_ = new RequestMediator(chessGameRqtBus, chessGameRqtMenu);
      serverComps_.chessGameReceiver_ = new RequestReceiver(serverComps_.chessGameMediator_);
    }
  };
} // namespace mbg

#endif // !_MBG_INITIALIZER_241117_H