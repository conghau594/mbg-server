//RequestMediator.h

#ifndef _MBG_REQUEST_MEDIATOR_H
#define _MBG_REQUEST_MEDIATOR_H

#include "iRequestMediator.h"
#include "iRequest.h"
#include "iRequestBus.h"
#include "iRequestMenu.h"

#ifdef _DEBUG
#include <iostream>
#endif
namespace mbg {
  class RequestMediator final : public iRequestMediator  {
    RequestQueue  requests_;
    iRequestBus*  requestBus_;
    iRequestMenu* requestMenu_;
    Bool shouldExit_ = false;

  public:
    RequestMediator(iRequestBus* rqtBus, iRequestMenu* rqtMenu,
             iCriticalArrayController* critArrCtrler = nullptr)
      : requestBus_(rqtBus), requestMenu_(rqtMenu), requests_(critArrCtrler)
    {}

    void run() override;
    void exit() override { shouldExit_ = true; }
    void receive(RequestQueue& rqtQueue) override {
      requests_.lockForGuest();
#ifdef _DEBUG
      std::cout << "\n\n...void RequestMediator::receive(RequestQueue& rqtQueue)...";
      std::cout << "\n  Server::RequestMediator thread has just received a queue of RequestInit's.";
#endif
      rqtQueue.swapTo(requests_);
      requests_.wakeUpHost();
      requests_.unlock();
    }

  private:
    Bool shouldExit() const { return shouldExit_; }
    RequestQueue listen() {
      requests_.lockForHost();
      RequestQueue cloneRequests;
      requests_.swapTo(cloneRequests);
      requests_.notifyOneGuest();
      requests_.unlock();
      return cloneRequests;
    }
  };
} // namespace mbg

#endif // !_MBG_REQUEST_MEDIATOR_H