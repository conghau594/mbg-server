//RequestMediator.cpp

#include "RequestMediator.h" 

#ifdef _DEBUG
#include <iostream>
#endif

namespace mbg {
  void RequestMediator::run() {
#ifdef _DEBUG
    std::cout << "\nA thread for a RequestMediator is running...";
#endif // _DEBUG

    while (!shouldExit()) {
      RequestQueue cloneRqts = listen();
      for (SizeType i = 0; i < cloneRqts.getSize(); ++i) {
        const SerializerBase* serializer = cloneRqts[i]->get(OBJ_SERIALIZER)->cast<SerializerBase>();
        ExInt index = serializer->getValue(INDEX_TAG);
        PathType path = requestMenu_->getPath(index);
        if (path.isNull()) {
          //TODO: Handle the case where the path is NULL_PATH in the method RequestMediator::run().
        }
        else {
          cloneRqts[i]->setPath(path);
          requestBus_->emit(cloneRqts[i]);
        }
      }
    }
  }



} // namespace mbg

