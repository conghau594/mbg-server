//GameRequestProcessor.h
#ifndef _MBG_GAME_REQUEST_PROCESSOR_H
#define _MBG_GAME_REQUEST_PROCESSOR_H

#include "iRequestProcessor.h"
#include "GameData.h"

namespace mbg {
  class GameRequestProcessor final : public RequestProcessorBase {
  public:
    GameRequestProcessor() = default;

    virtual void process(iRequest* request) override {
      GameData* gameData = static_cast<GameData*>(request->getData());
      if (gameData == nullptr) {
        return;
      }

    }
  };
} // namespace mbg

#endif // !_MBG_GAME_REQUEST_PROCESSOR_H