


#include "core/ExtendedType.h"
#include "core/DataField.h"
#include <iostream>

using namespace mbg;
using namespace std;

int main()
{
  std::cout << INDEX_TAG.getFieldName() << std::endl;

  ExInt x1();
  ExInt x2(19);
  ExStr x3("abd");
  ExStr x4();


  return 0;
}