//iMediator.h
#ifndef _MBG_I_MEDIATOR_H
#define _MBG_I_MEDIATOR_H

#include "iCriticalFiniteArray.h"
#include "iProcessor.h"

namespace mbg {
  class iMediator {
  public:
    virtual ~iMediator() = default;
    virtual void run() = 0;
    virtual void initialize() = 0;
    virtual void exit() = 0;

    virtual void subscribe(iProcessor* processor) = 0;
    virtual void emit(iRequest* request) = 0;
    virtual void receive(iRequestQueue* rqtQueue) = 0;
  };
} // namespace mbg
#endif // !_MBG_I_MEDIATOR_H
