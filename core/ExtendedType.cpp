// ExtendedType.inst.cpp

#include "ExtendedType.h"

namespace mbg {
  template class ExtendedType<Int>;
  template class ExtendedType<Uint>;
  template class ExtendedType<String>;
  template class ExtendedType<Float>;
  template class ExtendedType<char*>;
}