#include "Receiver.h"
#include "JsonExtractor.h"
#include "Request.h"

namespace mbg {
  void Receiver::run() {
    while (!shouldExit()) {
      iRawQueue* raws = listen();
      iRequestQueue* requests = process(raws);
      mediator_->receive(requests);
      delete raws;
    }
  }

  iRequestQueue* Receiver::process(iRawQueue* raws) {
    iRequestQueue* requests = new RequestQueue(MAX_REQUEST_QUEUE);
    for (SizeType i = 0; i < raws->getSize(); ++i) {
      iRequest* request = new Request(nullptr);// new JsonExtractor(raws[i]));
      requests->pushBack(request);
    }
    return requests;
  }
} // namespace mbg
