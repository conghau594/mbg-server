// RequestTranferor.h

#ifndef _MBG_REQUEST_TRANFEROR_H
#define _MBG_REQUEST_TRANFEROR_H

#include "RequestProcessorBase.h"
#include "iRequestReceiver.h"

namespace mbg {
  //TODO: Need to re-implement the class `RequestTranferor`.
  //      In fact, it is used for transferring requests from one mediator to another through 
  //      internal network.
  //      At the moment, it is connecting directly to one `Receiver` of each `Mediator`.
  class RequestTranferor final : public RequestProcessorBase {
    iRequestReceiver* receiver_;

  public:
    RequestTranferor(iRequestReceiver* receiver) : receiver_(receiver) {}

    void process(iRequest* request) override {
      String raw = request->makeRaw();
      receiver_->receive(raw.data());
    }
  };

} // namespace mbg
#endif // !_MBG_REQUEST_TRANFEROR_H