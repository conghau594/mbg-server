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

    while (!shouldExit()) {
      RawQueue raws = listen();
      RequestQueue requests;
      for (SizeType i = 0; i < raws.getSize(); ++i) {
        //TODO: Need to replace the concrete object JsonSerializer with a factory method.
        SerializerBase* serializer = new SimpleSerializer(raws[i]);
        requests.pushBack(new RequestInit(serializer));
      }

      mediator_->receive(requests);
    }
  }
} // namespace mbg
