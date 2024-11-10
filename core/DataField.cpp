// DataField.cpp

#include "DataField.h"

namespace mbg {
  template class DataField<ExUint>;
  template class DataField<ExInt>;
  template class DataField<ExChar>;
  template class DataField<ExStr>;
  template class DataField<ExFloat>;
  template class DataField<PathType>;

  constexpr DataField<PathType> INDEX_TAG("index");
  constexpr DataField<PathType> PLAYER_MOVE_TAG("playerMove");

  constexpr DataField<ExStr> LOGIN_SID_TAG("loginSID");
  constexpr DataField<ExStr> GAME_SID_TAG("gameSID");
  constexpr DataField<ExStr> CLIENT_CODE_TAG("clientCode");
  constexpr DataField<ExStr> USERNAME_TAG("username");
  constexpr DataField<ExStr> PASSWORD_TAG("password");
  constexpr DataField<ExStr> GAME_MODE_TAG("gameMode");
}
