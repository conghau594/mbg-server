// enums.h
#ifndef _MBG_ENUMS_H
#define _MBG_ENUMS_H

#include "primitives.h"

namespace mbg {
  enum {
    FULL_BIT_ONES = size_t(-1), ///<      
    MAX_RAW_QUEUE = 1 << 10,    ///< The maximum number of raw data that can be stored in the raw queue   
    MAX_REQUEST_QUEUE = 1 << 10 ///< The maximum number of requests that can be stored in the request queue
                                ///< Must be greater than or equal to MAX_RAW_QUEUE
  };

  enum GameType {
    GT_INVALID = -1,
    GT_CHESS,
    GT_CHINESE_CHESS
  };

  enum GameMode {
    GM_INVALID = -1,
    GM_COMPETITIVE,
    GM_PRACTICE,
    GM_FRIENDLY
  };

  //enum GameStatus {
  //  GS_INVALID = -1,
  //  GS_WAITING,
  //  GS_PLAYING,
  //  GS_FINISHED
  //};

  enum GameResult {
    ///< Result or status of game
    GR_1WIN      = 0x1,
    GR_2WIN      = 0x2,
    GR_3WIN      = 0x3,
    GR_4WIN      = 0x4,

    GR_UNDECIDED = 0x0,
    GR_DRAW      = 0xF,

    ///< Reasons of game ending: Checkmate, timeout, resign
    GR_CHECKMATE = 0x10,
    GR_TIMEOUT   = 0x20,
    GR_RESIGN    = 0x30,
  };


  //enum RequestType {
  //  RQT_VERIFY_LOGIN_SESSION_ID = 0x0,
  //  RQT_LOGIN,
  //  RQT_LOGOUT,
  //  RQT_CHANGE_PASSWORD,

  //  RQT_VERIFY_GAME = 0x0,
  //  RQT_FIRE_MOVE,
  //  RQT_FIND_GAME,
  //  RQT_FINISH_GAME,  ///Inner request
  //  RQT_RESIGN_GAME = RQT_FINISH_GAME
  //};

  //enum RequestIndex {
  //  IDX_LOGIN = 0x0,
  //  IDX_LOGOUT,
  //  IDX_CHANGE_PASSWORD,
  //  IDX_FIND_CHESS_GAME,
  //  IDX_MOVE_CHESS_PIECE,
  //  IDX_RESIGN_CHESS_GAME,
  //  IDX_ACKNOWLEDGE
  //};

  //enum ProcessorType {
  //  INVALID_PROCESSOR = -1,

  //  PRC_REQUEST_TRANSFER,
  //  PRC_SYSTEM_LOG,
  //  PRC_USER_SID_VERIFICATION,
  //  PRC_LOGIN,
  //  PRC_LOGOUT,
  //  PRC_PASSWORD_CHANGE,

  //  PRC_GAME_SID_VERIFICATION = PRC_USER_SID_VERIFICATION,
  //  PRC_GAME_MOVE,
  //  PRC_GAME_FIND,
  //  PRC_GAME_RESIGN,
  //  PRC_PLAYER_TIMEOUT,
  //  PRC_GAME_FINISH
  //};

  //enum MediatorType {
  //  MED_CHESS_GAME,
  //  MED_CHINESE_CHESS
  //};

  enum NotificationType {

  };
} // namespace mbg

#endif  // !_MBG_ENUMS_H
