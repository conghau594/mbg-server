//RequestReceiver.cpp

#include "RequestReceiver.h"
#include "JsonSerializer.h"
#include "SimpleSerializer.h"
#include "RequestInit.h"

#ifdef _DEBUG
#include <iostream>
#endif // _DEBUG

namespace mbg {
  void RequestReceiver::run() {
#ifdef _DEBUG
    std::cout << "\nA thread for a RequestReceiver is running...";
#endif // _DEBUG

    RequestQueue requests;
    SerializerBase* jsonObj;
    while (!shouldExit()) {
      RawQueue raws = listen();
      for (SizeType i = 0; i < raws.getSize(); ++i) {
        //TODO: Need to replace the concrete object JsonSerializer with a factory method.
        jsonObj = new SimpleSerializer(raws[i]);
        requests.pushBack(new RequestInit(jsonObj));
      }

      mediator_->receive(requests);
    }
  }
} // namespace mbg
