#ifndef _MBG_I_DATA_EXTRACTOR_H
#define _MBG_I_DATA_EXTRACTOR_H

#include "DataField.h"

namespace mbg {
  class iDataExtractor {
  public:
    virtual ~iDataExtractor() = default;
    virtual ExInt getValue(const IntField& field) = 0;
    virtual ExStr getValue(const StrField& field) = 0;
    virtual ExFloat getValue(const FloatField& field) = 0;
    virtual PathType getValue(const PathField& field) = 0;
  };
} // namespace mbg 

#endif // !_MBG_I_DATA_EXTRACTOR_H
