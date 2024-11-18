// enums.h
#ifndef _MBG_ENUMS_H
#define _MBG_ENUMS_H

#include "primitives.h"

namespace mbg {
  enum {
    FULL_BIT_ONES = size_t(-1), ///<    
    MAX_QUEUE_CAPACITY = 1 << 10, ///< The maximum number of elements that can be stored 
                                  ///< in a queue
    MAX_RAW_QUEUE = MAX_QUEUE_CAPACITY,    
    MAX_REQUEST_QUEUE = MAX_QUEUE_CAPACITY, ///< Must be greater than or equal to MAX_RAW_QUEUE
    
    NUM_BITS_FOR_REQUEST_TYPE = 4, ///< The number of bits used to represent the request type
  };

  enum GameType {
    GAME_TYPE_INVALID = -1,
    GAME_CHESS,
    GAME_CHN_CHESS
  };

  enum GameMode {
    GAME_MODE_INVALID = -1,
    GAME_MODE_COMPETITIVE,
    GAME_MODE_PRACTICE,
    GAME_MODE_FRIENDLY
  };

  //enum GameStatus {
  //  GS_INVALID = -1,
  //  GS_WAITING,
  //  GS_PLAYING,
  //  GS_FINISHED
  //};

  enum GameResult {
    ///< Result or status of game
    GAME_RSLT_PLR01_WIN    = 0x1,
    GAME_RSLT_PLR02_WIN    = 0x2,
    GAME_RSLT_PLR03_WIN    = 0x3,
    GAME_RSLT_PLR04_WIN    = 0x4,
    GAME_RSLT_PLR05_WIN    = 0x5,
    GAME_RSLT_PLR06_WIN    = 0x6,
    GAME_RSLT_PLR07_WIN    = 0x7,
    GAME_RSLT_PLR08_WIN    = 0x8,
    GAME_RSLT_PLR09_WIN    = 0x9,
    GAME_RSLT_PLR10_WIN    = 0xA,
    GAME_RSLT_PLR11_WIN    = 0xB,
    GAME_RSLT_PLR12_WIN    = 0xC,
    GAME_RSLT_PLR13_WIN    = 0xD,
    GAME_RSLT_PLR14_WIN    = 0xE,

    GAME_RSLT_UNDECIDED = 0x0,
    GAME_RSLT_DRAW      = 0xF,
  };

  enum GameEndReason {
    ///< Reason for game end
    GAME_END_RESIGN          = 0x10,
    GAME_END_TIMEOUT         = 0x20,
    GAME_END_CHECKMATE       = 0x30,      
    GAME_END_DISCONNECT      = 0x40,
    GAME_END_SERVER_SHUTDOWN = 0x50,
  };

  enum DataObjectType {
    OBJ_USER_DATA           = 0x0,
    OBJ_SERIALIZER          = 0x1,
    OBJ_CHESS_GAME_DATA     = 0x2,
    OBJ_CHN_CHESS_GAME_DATA = 0x3,
  };

  enum ServerStateEnum {
    SV_STATE_INVALID = -1,
    SV_STATE_BEGINNING,
    SV_STATE_RUNNING,
    SV_STATE_REJECTING,
    SV_STATE_PAUSING,
    SV_STATE_ENDING,
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
