// DataField.cpp

#include "DataField.h"

namespace mbg {
  template class DataField<ExUint>;
  template class DataField<ExInt>;
  template class DataField<ExChar>;
  template class DataField<ExStr>;
  template class DataField<ExFloat>;
  template class DataField<PathType>;

  constexpr PathField PATH_TAG("path");
  constexpr PathField PLAYER_MOVE_TAG("playerMove");

  constexpr StrField LOGIN_SID_TAG("loginSID");
  constexpr StrField GAME_SID_TAG("gameSID");
  constexpr StrField CLIENT_CODE_TAG("clientCode");
  constexpr StrField USERNAME_TAG("username");
  constexpr StrField PASSWORD_TAG("password");
  constexpr StrField GAME_MODE_TAG("gameMode");
} // namespace mbg
