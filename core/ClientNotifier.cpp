//ClientNotifier.cpp

#include "ClientNotifier.h"
#include "SerializerBase.h"
#include <sstream>

import chess.SDLChessGameTransceiver;


namespace mbg {
  void ClientNotifier::process(iRequest* request) {
    const SerializerBase* serializer = request->get(OBJ_SERIALIZER)->cast<SerializerBase>();
    String data = serializer->getValue(StrField(""));
    std::istringstream iss(data);
    Int windowId;
    iss >> windowId >> windowId >> windowId >> windowId;
    
    switch (windowId) {
    case 1:
      (*tranceiver)->receiveEvent(data);
      break;
    case 2:
      (*tranceiver2)->receiveEvent(data);
      break;
    case 3:
      (*tranceiver3)->receiveEvent(data);
      break;
    case 4:
      (*tranceiver4)->receiveEvent(data);
      break;
    default:
      break;
    }
  }
} // namespace mbg