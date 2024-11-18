//CriticalFiniteArray.h

#ifndef _MBG_CRITICAL_FINITE_ARRAY_H
#define _MBG_CRITICAL_FINITE_ARRAY_H

#include "Array.h"
#include "Utility.h"
#include "enums.h"
#include "iCriticalFiniteArray.h"
#include "CriticalArrayController.h"

namespace mbg {
  /*
    TODO: Need to refactor the template class `CriticalFiniteArray`
    - 'array_' should be a pointer to an array of T
    - 
   */
  template <typename T>
  class CriticalFiniteArray final : public iCriticalFiniteArray<T>
  {
    iCriticalArrayController* critArrCtrler_;
    Array<T> array_;
    SizeType maxSize_ = MAX_QUEUE_CAPACITY;

  public:/// Overrides from iFiniteArray
    CriticalFiniteArray(iCriticalArrayController* critArrCtrler = nullptr)
      : critArrCtrler_(critArrCtrler)
    {
      //TODO: Remove this. Should initiate this CriticalFiniteArray by a Factory method
      if(critArrCtrler_ == nullptr)
      {
        critArrCtrler_ = new CriticalArrayController(
          [this] { return not isEmpty(); },    //shouldWakeUpHost
          [this] { return not isFull(); });
      }
    }

    ~CriticalFiniteArray() {
      if (critArrCtrler_ != nullptr)
        delete critArrCtrler_; 
    }

    SizeType getSize() const override { return SizeType(array_.size()); }

    SizeType getMaxSize() const override { return maxSize_; }

    T& operator[](SizeType index) override {
      return array_[index];
    }

    const T& operator[](SizeType index) const override {
      return array_[index];
    }

    void pushBack(const T& item) {
      assert((!isFull()));
      array_.emplace_back(item);
    }

    T& popBack() override {
      T& result = array_.back();
      array_.pop_back();
      return result;
    }

    Bool isFull() const override {
      return array_.size() == maxSize_;
    }

    Bool isEmpty() const override {
      return array_.empty();
    }

    SizeType getAvailableSlotCount() const override {
      return maxSize_ - SizeType(array_.size());
    }

    void clear() override {
      array_.clear();
    }

    void swapTo(CriticalFiniteArray<T>& other) {
      array_.swap(other.array_);
    }

    //void cloneFrom(const CriticalFiniteArray<T>& source, SizeType srcIndex, SizeType destIndex, SizeType n) {
    //  Utility::copyMemory(array_.data() + destIndex, source.array_.data() + srcIndex, n * sizeof(T));
    //}
    //void cloneFrom(const CriticalFiniteArray<T>& source) {
    //  cloneFrom(source, 0, 0, SizeType(source.array_.size()));
    //}
    //void cloneFrom(const T* source, SizeType destIndex, SizeType n) override {
    //  Utility::copyMemory(array_.data() + destIndex, source, n * sizeof(T));
    //}
    //void cloneFrom(const iFiniteArray<T>* source, SizeType srcIndex, SizeType destIndex, SizeType n) override {
    //  source->copyTo(array_.data() + destIndex, srcIndex, n);
    //}
    //void cloneFrom(const iFiniteArray<T>* source) override {
    //  source->copyTo(array_.data(), 0, source->getSize());
    //}
    //void copyTo(CriticalFiniteArray<T>& dest, SizeType srcIndex, SizeType destIndex, SizeType n) const {
    //  Utility::copyMemory(dest.array_.data() + destIndex, array_.data() + srcIndex, n * sizeof(T));
    //}
    //void copyTo(CriticalFiniteArray<T>& dest) const {
    //  copyTo(dest, 0, 0, SizeType(array_.size()));
    //}
    //void copyTo(T* dest, SizeType srcIndex, SizeType n) const override {
    //  Utility::copyMemory(dest, array_.data() + srcIndex, n * sizeof(T));
    //}
    //void copyTo(iFiniteArray<T>* dest) const override {
    //  dest->cloneFrom(array_.data(), 0, SizeType(array_.size()));
    //}
    //void copyTo(iFiniteArray<T>* dest, SizeType srcIndex, SizeType destIndex, SizeType n) const override {
    //  dest->cloneFrom(array_.data() + srcIndex, destIndex, n);
    //}



  public:/// Overrides from iCriticalArrayController

    void lockForHost() override {
      critArrCtrler_->lockForHost();
    }

    void lockForGuest() override {
      critArrCtrler_->lockForGuest();
    }

    void unlock() override {
      critArrCtrler_->unlock();
    }

    void wakeUpHost() override {
      critArrCtrler_->wakeUpHost();
    }

    void notifyOneGuest() override {
      critArrCtrler_->notifyOneGuest();
    }

    void notifyAll() override {
      critArrCtrler_->notifyAll();
    }

    Bool isNoGuestWaiting() override {
      return critArrCtrler_->isNoGuestWaiting();
    }

  };


  extern template Array<iRequest*>;
  extern template Array<RawType>;

  extern template class CriticalFiniteArray<iRequest*>;
  extern template class CriticalFiniteArray<RawType>;

  using RequestQueue = CriticalFiniteArray<iRequest*>; /// A queue (finite array) of iRequest pointers.
  using RawQueue = CriticalFiniteArray<RawType>;       /// A queue (finite array) of RawType elements.

} // namespace mbg

#endif // !_MBG_CRITICAL_FINITE_ARRAY_H