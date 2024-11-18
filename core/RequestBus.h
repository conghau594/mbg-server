//RequestBus.h
#ifndef _MBG_REQUEST_BUS_H
#define _MBG_REQUEST_BUS_H

#include "iRequestBus.h"
#include "iRequestProcessor.h"

namespace mbg {
  class RequestBus final : public iRequestBus {
    ProcessorArray processors_;
    const SizeType numBitsForRqtType_;
  public:
    constexpr RequestBus(SizeType numBitsForRqtType) : numBitsForRqtType_(numBitsForRqtType) {}

    void emit(iRequest* request) override {
      SizeType dest = getDestination(request);
      processors_[dest]->process(request);
    }

    SizeType subscribe(iRequestProcessor* processor) override {
      processor->setID(processors_.size());
      processors_.emplace_back(processor);
      return processor->getID();
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