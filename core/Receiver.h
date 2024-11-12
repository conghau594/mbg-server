//Receiver.h

#ifndef _MBG_RECEIVER_H
#define _MBG_RECEIVER_H

#include "enums.h"
#include "iReceiver.h"
#include "iMediator.h"
#include "CriticalFiniteArray.h"

namespace mbg {
  class Receiver : public iReceiver {
  private:
    iMediator* mediator_;
    iRawQueue* raws_;
    Bool       shouldExit_;
  public:
    Receiver(iMediator* mediator)
      : mediator_(mediator), raws_(new RawQueue(MAX_RAW_QUEUE)), shouldExit_(false)
    {}
    
    ~Receiver() {
      delete raws_;
    }

  public:
    void run() override;
    void exit() override { shouldExit_ = true; }

    //TODO: Implement function receive(RawType data) in the class Receiver
    void receive(RawType data) override;
    

  private:
    iRequestQueue* process(iRawQueue* data);
    Bool shouldExit() const { return shouldExit_; }
    iRawQueue* listen() {
      raws_->lockForHost();
      iRawQueue* result = raws_;
      raws_ = new RawQueue(MAX_RAW_QUEUE);
      raws_->unlock();
      return result;
    }
  };
} // namespace mbg

#endif // !_MBG_RECEIVER_H
