//GameData.h
#ifndef _MBG_GAME_DATA_H
#define _MBG_GAME_DATA_H

#include "ExtendedType.h"
#include "enums.h"

namespace mbg {
  class GameData final {
    String      gameID_;
    ExStr       gameSID_;
    GameType    gameType_;
    GameMode    gameMode_;
    GameResult  gameResult_;
    /*iBoard*   gameBoard_*/

  public:
    GameData() = default;

    const String& getGameID() const { return gameID_; }
    GameType getGameType() const { return gameType_; }
    GameMode getGameMode() const { return gameMode_; }

    void setGameSID(const ExStr& gameSID) { gameSID_ = gameSID; }

  };
} // namespace mbg
#endif // !_MBG_GAME_DATA_H
