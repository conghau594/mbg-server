//DataField.h

#ifndef _MBG_DATA_FIELD_H
#define _MBG_DATA_FIELD_H

#include "primitives.h"
#include "String.h"
#include "ExtendedType.h"
#include "iDataField.h"

namespace mbg {
  /// @brief A template class representing a data field of a data extractor object (JSON, XML,...) .
  /// @tparam T The type of the data field.
  template <typename T>
  class DataField : public iDataField {
  private:
    
    const char* fieldName_; ///< @brief The name of the data field.

  public:
    /// @brief Constructor to initialize the data field with a name.
    /// @param fieldName The name of the data field.
    constexpr DataField(const char* fieldName) : fieldName_(fieldName) {}

    /// @brief Get the name of the data field.
    /// @return The name of the data field.
    constexpr const char* getFieldName() const override {
      return fieldName_;
    }
  };

  extern template class DataField<ExInt>;
  extern template class DataField<ExStr>;
  extern template class DataField<ExChar>;
  extern template class DataField<ExFloat>;
  extern template class DataField<PathType>;

  using IntField = DataField<ExInt>;    ///< @brief Type of data fields having an integer value.
  using StrField = DataField<ExStr>;    ///< @brief Type of data fields having a string value.
  using CharField = DataField<ExChar>;  ///< @brief Type of data fields having a character value.
  using FloatField = DataField<ExChar>; ///< @brief Type of data fields having a float value.
  using PathField = DataField<PathType>;///< @brief Type of data fields that store game move of player or the path for traveling through request processor.

  extern const DataField<PathType> PATH_TAG;        ///< @brief A constant data field representing the field "path" of extractor objects.
  extern const DataField<PathType> PLAYER_MOVE_TAG; ///< @brief A constant data field representing the field "playerMove" of extractor objects.

  extern const DataField<ExStr> LOGIN_SID_TAG;      ///< @brief A constant data field representing the field "loginSID" of extractor objects.
  extern const DataField<ExStr> GAME_SID_TAG;       ///< @brief A constant data field representing the field "gameSID" of extractor objects.  
  extern const DataField<ExStr> CLIENT_CODE_TAG;    ///< @brief A constant data field representing the field "clientCode" of extractor objects.
  extern const DataField<ExStr> USERNAME_TAG;       ///< @brief A constant data field representing the field "username" of extractor objects.
  extern const DataField<ExStr> PASSWORD_TAG;       ///< @brief A constant data field representing the field "password" of extractor objects.
  extern const DataField<ExStr> GAME_MODE_TAG;      ///< @brief A constant data field representing the field "gameMode" of extractor objects.

} // namespace mbg

#endif  // _MBG_DATA_FIELD_H
