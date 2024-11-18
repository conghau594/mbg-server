//ClientNotifier.h

#ifndef _MBG_CLIENT_NOTIFIER_H
#define _MBG_CLIENT_NOTIFIER_H

#include "RequestProcessorBase.h"
#include <memory>



namespace mbg {
  class SDLChessGameTransceiver;
  //TODO: Need to re-implement the class ClientNotifier
  //      This class is dedicated to transferring/notifying to the clients that own the requests.
  class ClientNotifier final : public RequestProcessorBase {
  public:
    ClientNotifier() = default;

    void process(iRequest* request) override;
  
    std::shared_ptr<SDLChessGameTransceiver>* tranceiver;
    std::shared_ptr<SDLChessGameTransceiver>* tranceiver2;
    std::shared_ptr<SDLChessGameTransceiver>* tranceiver3;
    std::shared_ptr<SDLChessGameTransceiver>* tranceiver4;
    
  };
} // namespace mbg

#endif // !_MBG_CLIENT_NOTIFIER_H