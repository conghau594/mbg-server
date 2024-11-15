//RequestBus.h
#ifndef _MBG_REQUEST_BUS_H
#define _MBG_REQUEST_BUS_H

#include "iRequestBus.h"
#include "iRequestProcessor.h"

namespace mbg {
  class RequestBus final : public iRequestBus {
    ProcessorArray processors_;
    SizeType numBitsForRqtType_;
  public:
    RequestBus(SizeType numBitsForRqtType) : numBitsForRqtType_(numBitsForRqtType) {}

    void emit(iRequest* request) override {
      SizeType dest = getDestination(request);
      processors_[dest]->process(request);
    }

    void subscribe(iRequestProcessor* processor) override {
      processors_.emplace_back(processor);
      processor->setID(processors_.size() - 1);
    }

    void unsubscribe(iRequestProcessor* processor) override {
      processors_[processor->getID()] = nullptr;
    }

  private:
    PathType getDestination(iRequest* request) const {
      return request->extractDestination(numBitsForRqtType_);
    }
  };
} // namespace mbg

#endif // !_MBG_REQUEST_BUS_H