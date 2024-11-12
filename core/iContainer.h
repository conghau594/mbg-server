//iContainer.h

#ifndef _MBG_I_CONTAINER_H
#define _MBG_I_CONTAINER_H

#include "primitives.h"

namespace mbg {
  class iContainer {
  public:
    virtual ~iContainer() = default;


    /**
     * @brief Gets the size of the array.
     *
     * This method returns the number of elements currently stored in the array.
     * Must be implemented by derived classes.
     *
     * @return SizeType The number of elements in the array.
     */
    virtual SizeType getSize() const = 0;

    /**
     * @brief Checks if the array is empty.
     *
     * This method checks whether the array has no elements.
     * If the array is empty, it returns true; otherwise, it returns false.
     * Must be implemented by derived classes.
     *
     * @return Bool True if the array is empty, false otherwise.
     */
    virtual Bool isEmpty() const = 0;
    
    /**
     * @brief Clears the array.
     *
     * This method removes all elements from the array, leaving it empty.
     * Must be implemented by derived classes.
     */
    virtual void clear() = 0;
  };
} // namespace mbg

#endif  // !_MBG_I_CONTAINER_H

