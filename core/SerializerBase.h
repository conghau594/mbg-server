//SerializerBase.h
#ifndef _MBG_SERIALIZER_BASE_H
#define _MBG_SERIALIZER_BASE_H

#include "iSerializer.h"
#include "DataObject.h"
#include "enums.h"

namespace mbg {
  class SerializerBase : public iSerializer, public DataObject {
  public:
    SerializerBase() : DataObject(OBJ_SERIALIZER) {}
    constexpr static int TYPE_ID = OBJ_SERIALIZER;

  };
}// namespace mbg

#endif // !_MBG_SERIALIZER_BASE_H
