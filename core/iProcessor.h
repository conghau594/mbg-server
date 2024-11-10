//iProcessor.h

#ifndef _MBG_I_PROCESSOR_H
#define _MBG_I_PROCESSOR_H

#include "iRequest.h"

namespace mbg {
  class iProcessor {
  public:
    virtual ~iProcessor() = default;
    virtual void process(iRequest* request) = 0;
  };
} // namespace mbg
#endif // !_MBG_I_PROCESSOR_H
