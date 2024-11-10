//DataField.h

#ifndef _MBG_DATA_FIELD_H
#define _MBG_DATA_FIELD_H

#include "ExtendedType.h"
#include "basetypes.h"
#include "iDataField.h"

namespace mbg {
  template <typename T>
  class DataField : public iDataField {
  private:
    const char* mFieldName;

  public:
    constexpr DataField(const char* fieldName) : mFieldName(fieldName) {}

    constexpr const char* getFieldName() const override {
      return mFieldName;
    }
  };

  extern template class DataField<ExInt>;
  extern template class DataField<ExStr>;
  extern template class DataField<ExChar>;
  extern template class DataField<ExFloat>;
  extern template class DataField<PathType>;

  using IntField = DataField<ExInt>;
  using StrField = DataField<ExStr>;
  using CharField = DataField<ExChar>;
  using FloatField = DataField<ExChar>;
  using PathField = DataField<PathType>;

  extern const DataField<PathType> INDEX_TAG;
  extern const DataField<PathType> PLAYER_MOVE_TAG;

  extern const DataField<ExStr> LOGIN_SID_TAG;
  extern const DataField<ExStr> GAME_SID_TAG;
  extern const DataField<ExStr> CLIENT_CODE_TAG;
  extern const DataField<ExStr> USERNAME_TAG;
  extern const DataField<ExStr> PASSWORD_TAG;
  extern const DataField<ExStr> GAME_MODE_TAG;

}

#endif
