//iRequestBus.h
#ifndef _MBG_I_REQUEST_BUS_H
#define _MBG_I_REQUEST_BUS_H

#include "iRequest.h"
#include "iRequestProcessor.h"

namespace mbg {
  class iRequestBus {
    public:
    virtual ~iRequestBus() = default;
    virtual void emit(iRequest* request) = 0;
    virtual void subscribe(iRequestProcessor* processor) = 0;
    virtual void unsubscribe(iRequestProcessor* processor) = 0;
  };
} // namespace mbg
#endif // !_MBG_I_REQUEST_BUS_H
