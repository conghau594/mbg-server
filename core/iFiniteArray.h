//iFiniteArray.h
#ifndef _MBG_I_FINITE_ARRAY_H
#define _MBG_I_FINITE_ARRAY_H

#include "primitives.h"
#include "iContainer.h"

namespace mbg {
  /**
   * @brief Interface for a finite array container.
   * 
   * This class provides an interface for a finite array container that supports
   * basic operations such as adding and removing elements, accessing elements
   * by index, checking if the array is full, collapsing the array, and moving
   * elements to another array.
   * 
   * @tparam T The type of elements stored in the array.
   */
  template <typename T>
  class iFiniteArray : public iContainer {
  public:
    virtual ~iFiniteArray() = default;


    /**
     * @brief Gets the maximum size of the array.
     *
     * This method returns the maximum number of elements that can be stored in the array.
     * Must be implemented by derived classes.
     *
     * @return SizeType The maximum number of elements the array can hold.
     */
    virtual SizeType getMaxSize() const = 0;

    /**
     * @brief Accesses the element at the specified index.
     * 
     * This method provides access to the element at the specified index.
     * If the index is out of bounds, the behavior is undefined.
     * Must be implemented by derived classes.
     * 
     * @param index The index of the element to access.
     * @return T& A reference to the element at the specified index.
     */
    virtual T& operator[](SizeType index) = 0;

    /**
     * @brief Accesses the element at the specified index (const version).
     * 
     * This method provides access to the element at the specified index.
     * If the index is out of bounds, the behavior is undefined.
     * Must be implemented by derived classes.
     * 
     * @param index The index of the element to access.
     * @return const T& A const reference to the element at the specified index.
     */
    virtual const T& operator[](SizeType index) const = 0;

    /**
     * @brief Adds an element to the end of the array.
     * 
     * This method adds a new element to the end of the array. If the array is full,
     * the behavior is undefined.
     * Must be implemented by derived classes.
     * 
     * @param value The value to be added to the array.
     */
    virtual void pushBack(const T& item) = 0;
    //virtual void pushBack(T&& value) = 0;

    /**
     * @brief Removes the last element from the array.
     * 
     * This method removes the last element from the array and returns it. If the array
     * is empty, the behavior is undefined.
     * Must be implemented by derived classes.
     * 
     * @return T& A reference to the removed element.
     */
    virtual T& popBack() = 0;
    
    /**
     * @brief Checks if the array is full.
     * 
     * This method checks whether the array has reached its maximum capacity.
     * If the array is full, it returns true; otherwise, it returns false.
     * Must be implemented by derived classes.
     * 
     * @return Bool True if the array is full, false otherwise.
     */
    virtual Bool isFull() const = 0;
        
    /**
     * @brief Gets the number of available slots in the array.
     * 
     * This method returns the number of available slots in the array.
     * If the array is full, it returns 0.
     * Must be implemented by derived classes.
     * 
     * @return SizeType The number of available slots in the array.
     */
    virtual SizeType getAvailableSlotCount() const = 0;

    /**
     * @brief Collapses the array.
     * 
     * This method collapses the array, removing any gaps between elements.
     * The exact behavior is implementation-defined and must be provided by derived classes.
     */
    virtual void collapse() = 0;



    /**
     * @brief Clones elements from a source (raw) array to the current array.
     * 
     * This method copies `n` elements from the `source` (raw) array starting at the beginning
     * to the current array starting at `destIndex`. The exact behavior is implementation-defined
     * and must be provided by derived classes.
     * 
     * @param source The source array from which elements will be cloned.
     * @param destIndex The starting index in the current array where elements will be cloned to.
     * @param n The number of elements to clone.
     */
    virtual void cloneFrom(const T* source, SizeType destIndex, SizeType n) = 0;

    /**
     * @brief Clones elements from another finite array to the current array.
     * 
     * This method copies all elements from the `source` array to the current array.
     * The exact behavior is implementation-defined and must be provided by derived classes.
     * 
     * @param source The source finite array from which elements will be cloned.
     */
    virtual void cloneFrom(const iFiniteArray<T>* source) = 0;

    /**
     * @brief Clones a specified number of elements from a source finite array to the current array.
     * 
     * This method copies `n` elements from the `source` array starting at `srcIndex`
     * to the current array starting at `destIndex`. The exact behavior is implementation-defined
     * and must be provided by derived classes.
     * 
     * @param source The source finite array from which elements will be cloned.
     * @param srcIndex The starting index in the source array from which elements will be cloned.
     * @param destIndex The starting index in the current array where elements will be cloned to.
     * @param n The number of elements to clone.
     */
    virtual void cloneFrom(const iFiniteArray<T>* source, SizeType srcIndex, SizeType destIndex, SizeType n) = 0;

    /**
     * @brief Copies a specified number of elements to a destination array.
     * 
     * This method copies `n` elements starting from `srcIndex` in the current array
     * to the destination array `dest`. The elements are not removed from the current array.
     * The exact behavior is implementation-defined and must be provided by derived classes.
     * 
     * @param dest The destination array to which elements will be copied.
     * @param srcIndex The starting index in the current array from which elements will be copied.
     * @param n The number of elements to copy.
     */
    virtual void copyTo(T* dest, SizeType srcIndex, SizeType n) const = 0;

    /**
     * @brief Copies all elements to another array.
     * 
     * This method copies all elements from the current array to the destination array.
     * The elements are not removed from the current array but are added to the destination array.
     * The exact behavior is implementation-defined and must be provided by derived classes.
     * 
     * @param dest The destination array to which elements will be copied.
     */
    virtual void copyTo(iFiniteArray<T>* dest) const = 0;

    /**
     * @brief Copies a specified number of elements to another finite array.
     * 
     * This method copies `n` elements starting from `srcIndex` in the current array
     * to the destination array `dest` starting at `destIndex`. The elements are not
     * removed from the current array. The exact behavior is implementation-defined
     * and must be provided by derived classes.
     * 
     * @param dest The destination finite array to which elements will be copied.
     * @param srcIndex The starting index in the current array from which elements will be copied.
     * @param destIndex The starting index in the destination array where elements will be copied to.
     * @param n The number of elements to copy.
     */
    virtual void copyTo(iFiniteArray<T>* dest, SizeType srcIndex, SizeType destIndex, SizeType n) const = 0;

  };  
} // namespace mbg

#endif // !_MBG_I_FINITE_ARRAY_TMPL_H

