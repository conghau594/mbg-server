//CriticalFiniteArray.h

#ifndef _MBG_CRITICAL_FINITE_ARRAY_H
#define _MBG_CRITICAL_FINITE_ARRAY_H

#include "Array.h"
#include "Utility.h"

#include "iCriticalFiniteArray.h"
#include "CriticalArrayController.h"

namespace mbg {
  template <typename T>
  class CriticalFiniteArray final : public iCriticalFiniteArray<T>
  {
    iCriticalArrayController* criticalSectionController_;
    std::vector<T> array_;
    SizeType maxSize_;

  public:/// Overrides from iFiniteArray
    CriticalFiniteArray(SizeType maxSize) 
      : criticalSectionController_(new CriticalArrayController(
          [this] { return not isEmpty(); },  //shouldWakeUpHost
          [this] { return not isFull(); })), //shouldNotifyGuest
        maxSize_(maxSize) 
    { }
    
    ~CriticalFiniteArray() {
      delete criticalSectionController_;
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
      assert((isFull()));
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

    void collapse() override {
      //TODO: Implement this method in the CriticalFiniteArray class
    }


    void cloneFrom(const CriticalFiniteArray<T>& source, SizeType srcIndex, SizeType destIndex, SizeType n) {
      Utility::copyMemory(array_.data() + destIndex, source.array_.data() + srcIndex, n * sizeof(T));
    }
    

    void cloneFrom(const CriticalFiniteArray<T>& source) {
      cloneFrom(source, 0, 0, SizeType(source.array_.size()));
    }

    void cloneFrom(const T* source, SizeType destIndex, SizeType n) override {
      Utility::copyMemory(array_.data() + destIndex, source, n * sizeof(T));
    }


    void cloneFrom(const iFiniteArray<T>* source, SizeType srcIndex, SizeType destIndex, SizeType n) override {
      source->copyTo(array_.data() + destIndex, srcIndex, n);
    }

    void cloneFrom(const iFiniteArray<T>* source) override {
      source->copyTo(array_.data(), 0, source->getSize());
    }

    void copyTo(CriticalFiniteArray<T>& dest, SizeType srcIndex, SizeType destIndex, SizeType n) const {
      Utility::copyMemory(dest.array_.data() + destIndex, array_.data() + srcIndex, n * sizeof(T));
    }

    void copyTo(CriticalFiniteArray<T>& dest) const {
      copyTo(dest, 0, 0, SizeType(array_.size()));
    }

    void copyTo(T* dest, SizeType srcIndex, SizeType n) const override {
      Utility::copyMemory(dest, array_.data() + srcIndex, n * sizeof(T));
    }


    void copyTo(iFiniteArray<T>* dest) const override {
      dest->cloneFrom(array_.data(), 0, SizeType(array_.size()));
    }

    void copyTo(iFiniteArray<T>* dest, SizeType srcIndex, SizeType destIndex, SizeType n) const override {
      dest->cloneFrom(array_.data() + srcIndex, destIndex, n);
    }

    void clear() override {
      array_.clear();
    }

  public:/// Overrides from iCriticalArrayController

    void lockForHost() override {
      criticalSectionController_->lockForHost();
    }

    void lockForGuest() override {
      criticalSectionController_->lockForGuest();
    }

    void unlock() override {
      criticalSectionController_->unlock();
    }

    void wakeUpHost() override {
      criticalSectionController_->wakeUpHost();
    }

    void notifyOneGuest() override {
      criticalSectionController_->notifyOneGuest();
    }

    void notifyAll() override {
      criticalSectionController_->notifyAll();
    }

    Bool isNoGuestWaiting() override {
      return criticalSectionController_->isNoGuestWaiting();
    }

  };


  extern template class CriticalFiniteArray<iRequest*>;
  extern template class CriticalFiniteArray<RawType>;

  using RequestQueue = CriticalFiniteArray<iRequest*>; /// A queue (finite array) of iRequest pointers.
  using RawQueue = CriticalFiniteArray<RawType>;       /// A queue (finite array) of RawType elements.

} // namespace mbg

#endif // !_MBG_CRITICAL_FINITE_ARRAY_H