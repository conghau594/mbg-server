//RequestReceiver.cpp

#include "RequestReceiver.h"
#include "JsonExtractor.h"
#include "Request.h"

namespace mbg {
  void RequestReceiver::run() {
    RequestQueue requests;
    iDataExtractor* jsonObj;
    while (!shouldExit()) {
      RawQueue raws = listen();
      for (SizeType i = 0; i < raws.getSize(); ++i) {
        //TODO: Need to replace the concrete object JsonExtractor with a factory method.
        jsonObj = new JsonExtractor(Json::parse(raws[i]));
        requests.pushBack(new Request(jsonObj));
      }
      mediator_->receive(requests);
    }
  }
} // namespace mbg
