// enums.h
#ifndef _MBG_ENUMS_H
#define _MBG_ENUMS_H

#include "basetypes.h"

namespace mbg {
  enum {
    FULL_BIT_ONES = PathType(-1),
    MAX_REQUEST_QUEUE = 1 << 10,

  };
  enum RequestType {
    OUT_REQUEST_VERIFY_LOGIN_SESSION_ID = 0x0,
    OUT_REQUEST_LOGIN,
    OUT_REQUEST_LOGOUT,
    OUT_REQUEST_CHANGE_PASSWORD,

    OUT_REQUEST_VERIFY_GAME = 0x0,
    OUT_REQUEST_FIRE_MOVE,
    OUT_REQUEST_FIND_GAME,
    IN_REQUEST_FINISH_GAME,
    OUT_REQUEST_RESIGN_GAME = IN_REQUEST_FINISH_GAME
  };

  enum RequestIndex {
    INDEX_LOGIN = 0x0,
    INDEX_LOGOUT,
    INDEX_CHANGE_PASSWORD,
    INDEX_FIND_CHESS_GAME,
    INDEX_MOVE_CHESS_PIECE,
    INDEX_RESIGN_CHESS_GAME,
    INDEX_ACKNOWLEDGE
  };

  enum ProcessorType {
    PROCESSOR_USER_SESSION_ID_VERIFICATION = 0x0,
    PROCESSOR_LOGIN_AUTHENTICATTION,
    PROCESSOR_LOGOUT_AUTHENTICATION,
    PROCESSOR_PASSWORD_CHANGE,
    PROCESSOR_CHESS_GAME_COORDINATION,
    PROCESSOR_CHINESE_CHESS_COORDINATION,

    PROCESSOR_GAME_SESSION_ID = 0x0,
    PROCESSOR_GAME_MOVE,
    PROCESSOR_GAME_FINDER,
    PROCESSOR_GAME_RESIGN,
    PROCESSOR_PLAYER_TIMEOUT,
    PROCESSOR_GAME_FINISH
  };

  enum NotificationType {

  };
}

#endif
