//RequestMediator.cpp

#include "RequestMediator.h" 

namespace mbg {
  void RequestMediator::run() {
    while (!shouldExit()) {
      RequestQueue cloneRequests = listen();
      for (SizeType i = 0; i < cloneRequests.getSize(); ++i) {
        ExInt index = cloneRequests[i]->getValue(INDEX_TAG);
        PathType path = requestMenu_->getPath(index);
        if (path == NULL_PATH) {
          //TODO: Handle the case where the path is NULL_PATH in the method RequestMediator::run().
        }
        else {
          cloneRequests[i]->setPath(path);
          requestBus_->emit(cloneRequests[i]);
        }
      }
    }
  }



} // namespace mbg

