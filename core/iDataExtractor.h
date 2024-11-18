//iDataExtactor.h

#ifndef _MBG_I_DATA_EXTRACTOR_H
#define _MBG_I_DATA_EXTRACTOR_H


#include "DataObject.h"


namespace mbg {
  class iDataExtractor {
  public:
    virtual ~iDataExtractor() = default;
    virtual DataObject* get(int type) = 0;
    virtual void set(DataObject* dataPtr) = 0;
  };
} // namespace mbg

#endif // !_MBG_I_DATA_EXTRACTOR_H