//Receiver.h

#ifndef _MBG_RECEIVER_H
#define _MBG_RECEIVER_H

#include "enums.h"
#include "iRequestReceiver.h"
#include "iRequestMediator.h"
#include "CriticalFiniteArray.h"

namespace mbg {
  class RequestReceiver final : public iRequestReceiver {
  private:
    RawQueue   raws_;
    iRequestMediator* mediator_;
    Bool       shouldExit_ = false;
  public:
    RequestReceiver(iRequestMediator* mediator, iCriticalArrayController* critArrCtrler = nullptr)
      : mediator_(mediator), raws_(critArrCtrler)
    {}

  public:
    void run() override;
    void exit() override { shouldExit_ = true; }

    void receive(RawType data) override {
      //TODO: Need to re-implement RequestReceiver::receive() method.
      //      This is just a simple implementation. In fact, this class is used to receive data 
      //      from the network.
      raws_.lockForGuest();
      raws_.pushBack(data);
      raws_.wakeUpHost();
      raws_.unlock();
    }
    

  private:
    Bool shouldExit() const { return shouldExit_; }
    
    
    
    RawQueue listen() {
      raws_.lockForHost();
      RawQueue cloneRaws;
      raws_.swapTo(cloneRaws);
      raws_.notifyOneGuest();
      raws_.unlock();
      return cloneRaws;
    }
  };
} // namespace mbg

#endif // !_MBG_RECEIVER_H
