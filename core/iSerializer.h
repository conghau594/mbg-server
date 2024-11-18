#ifndef _MBG_I_SERIALIZER_H
#define _MBG_I_SERIALIZER_H

#include "DataField.h"

namespace mbg {
  class iSerializer {
  public:
    virtual ~iSerializer() = default;
    virtual ExInt getValue(const IntField& field) const = 0;
    virtual ExStr getValue(const StrField& field) const = 0;
    virtual ExFloat getValue(const FloatField& field) const = 0;
    virtual PathType getValue(const PathField& field) const = 0;

  };

} // namespace mbg 

#endif // !_MBG_I_SERIALIZER_H
