// ExtendedType.inst.cpp

#include "ExtendedType.h"

namespace mbg {
  template class ExtendedType<Int>;
  template class ExtendedType<Uint>;
  template class ExtendedType<SizeType>;
  template class ExtendedType<String>;
  template class ExtendedType<Float>;
  template class ExtendedType<char*>;

  constexpr ExInt    NULL_INT;
  constexpr ExUint   NULL_UINT;
  constexpr ExSize   NULL_SIZE;
  constexpr ExFloat  NULL_FLOAT;
  const     ExStr    NULL_STRING;
  constexpr ExChar   NULL_CHAR;
  constexpr PathType NULL_PATH;

} // namespace mbg