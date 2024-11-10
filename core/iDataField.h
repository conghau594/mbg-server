//iDataField.h

#ifndef _MBG_I_DATA_FIELD_H
#define _MBG_I_DATA_FIELD_H

namespace mbg {
  class iDataField {
  public:
    virtual constexpr ~iDataField() = default;
    virtual constexpr const char* getFieldName() const = 0;
  };
}

#endif
