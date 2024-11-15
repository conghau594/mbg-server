//ClientNotifier.h

#ifndef _MBG_CLIENT_NOTIFIER_H
#define _MBG_CLIENT_NOTIFIER_H

#include "iRequestProcessor.h"

namespace mbg {
  //TODO: Need to re-implement the class ClientNotifier
  //      This class is dedicated to transferring/notifying to the clients that own the requests.
  class ClientNotifier final : public RequestProcessorBase {
  public:
    ClientNotifier() = default;

    virtual void process(iRequest* request) override {

    }
  };
} // namespace mbg

#endif // !_MBG_CLIENT_NOTIFIER_H