//RequestProcessorBase.h

#ifndef _MBG_REQUEST_PROCESSOR_BASE_H
#define _MBG_REQUEST_PROCESSOR_BASE_H

#include "iRequestProcessor.h"

namespace mbg {
  class RequestProcessorBase : public iRequestProcessor {
    Int id_;
  public:
    RequestProcessorBase() = default;
    virtual void setID(Int id) override { id_ = id; }
    virtual Int getID() const override { return id_; }
  };
} // namespace mbg

#endif // !_MBG_REQUEST_PROCESSOR_BASE_H