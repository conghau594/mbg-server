#ifndef _MBG_IDATA_EXTRACTOR_H
#define _MBG_IDATA_EXTRACTOR_H

#include "DataField.h"

namespace mbg {
  class iDataExtractor {
  public:
    virtual ~iDataExtractor() = default;
    virtual ExInt getValue(IntField field) = 0;
    virtual ExStr getValue(StrField field) = 0;
    virtual ExFloat getValue(FloatField field) = 0;
    virtual PathType getValue(PathField field) = 0;
  };
} // namespace mbg 

#endif
