//iRequestMediator .h
#ifndef _MBG_I_REQUEST_MEDIATOR_H
#define _MBG_I_REQUEST_MEDIATOR_H

#include "CriticalFiniteArray.h"

namespace mbg {
  class iRequestMediator {
  public:
    virtual ~iRequestMediator() = default;
    virtual void run() = 0;
    virtual void exit() = 0;
    virtual void receive(RequestQueue& rqtQueue) = 0;
  };
} // namespace mbg
#endif // !_MBG_I_REQUEST_MEDIATOR_H
