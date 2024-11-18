//DataObject.h
#ifndef _MBG_DATA_OBJECT_H
#define _MBG_DATA_OBJECT_H

#include <cassert>

namespace mbg {
  class DataObject {
  private:
    const int type_;
  public:
    constexpr DataObject(int type) : type_(type) {}
    virtual ~DataObject() = default;
    
    constexpr int getType() const { return type_; } 

    template <typename T>
    const T* cast() const {
      assert(type_ == T::TYPE_ID);
      return static_cast<const T*>(this);
    }

  };
} // namespace mbg

#endif // !_MBG_DATA_OBJECT_H