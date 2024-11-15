//iRequestProcessor.h

#ifndef _MBG_I_REQUEST_PROCESSOR_H
#define _MBG_I_REQUEST_PROCESSOR_H

#include "iRequest.h"
#include "Array.h"

namespace mbg {
  class iRequestProcessor {
  public:
    virtual ~iRequestProcessor() = default;
    virtual void process(iRequest* request) = 0;
    virtual void setID(Int id) = 0;
    virtual Int getID() const = 0;
  };

  extern template Array<iRequestProcessor*>;
  using ProcessorArray = Array<iRequestProcessor*>;

  class RequestProcessorBase : public iRequestProcessor {
    Int id_;
  public:
    RequestProcessorBase() = default;
    void setID(Int id) override { id_ = id; }
    Int getID() const override { return id_; }
  };
} // namespace mbg
#endif // !_MBG_I_REQUEST_PROCESSOR_H
