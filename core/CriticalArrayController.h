//iCriticalArrayController.h.h

#ifndef _MBG_CRITICAL_ARRAY_CONTROLLER_H
#define _MBG_CRITICAL_ARRAY_CONTROLLER_H

#include "iCriticalArrayController.h"
#include "Mutex.h"
#include "Function.h"
#include "ConditionVariable.h"

namespace mbg {
  /**
   * @brief Manages critical arrays with host and guest conditions.
   * 
   * This class provides mechanisms to lock and unlock critical arrays
   * for both host (the array's owner) and guests (the threads 
   * writing data to the array). It ensures proper synchronization
   * using mutexes and condition variables. It also allows for notifying
   * guests and waking up the host based on specified conditions.
   */
  class CriticalArrayController final : public iCriticalArrayController {
  private:

    Mutex mutex_;             ///< Mutex for synchronizing access to the critical section.
    ConditionVariable host_;  ///< Condition variable for the host to wait on.
    ConditionVariable guest_; ///< Condition variable for the guests to wait on.

    Function<Bool()> shouldWakeUpHost_;  ///< Condition to wake up the host.
    Function<Bool()> shouldNotifyGuest_; ///< Condition to notify a guest.

    Int waitingGuests_ = 0;   ///< Number of guests currently waiting.
    Bool locked_ = false;     ///< Flag indicating if the critical array is locked.

  public:

    /**
     * @brief Constructs a CriticalArrayController with specified conditions.
     * 
     * @param shouldWakeUpHost Condition to wake up the host.
     * @param shouldNotifyGuest Condition to notify a guest.
     */
    CriticalArrayController(
      Function<Bool()> shouldWakeUpHost, Function<Bool()> shouldNotifyGuest)
      : shouldWakeUpHost_(shouldWakeUpHost),
        shouldNotifyGuest_(shouldNotifyGuest)
    {}

    /**
     * @brief Locks the critical array for the host.
     * 
     * This method locks the critical array for the host (the array's owner).
     * It waits until the array is not locked and the wake-up condition for the host is met.
     * Once these conditions are satisfied, the array is locked for the host.
     */
    void lockForHost() override {
      UniqueLock lock(mutex_);
      host_.wait(
        lock,
        [this] { return (not locked_) && shouldWakeUpHost_(); });

      locked_ = true;
    }

    /**
     * @brief Locks the critical array for a guest.
     * 
     * This method locks the critical array for a guest (a thread writing data to the array).
     * It increments the count of waiting guests, then waits until the array is not locked
     * and the notify condition for the guest is met. Once these conditions are satisfied,
     * the array is locked for the guest and the count of waiting guests is decremented.
     */
    void lockForGuest() override {
      UniqueLock lock(mutex_);
      ++waitingGuests_;
      guest_.wait(
        lock, 
        [this] { return (not locked_) && shouldNotifyGuest_(); });

      locked_ = true;
      --waitingGuests_;
    }


    /**
     * @brief Unlocks the critical array.
     * 
     * This method unlocks the critical array, allowing other threads to access it.
     * It sets the locked flag to false.
     */
    void unlock() override { locked_ = false; }


    /**
     * @brief Wakes up the host.
     * 
     * This method notifies the host condition variable, waking up the host
     * if it is waiting on the condition variable.
     */
    void wakeUpHost() override { host_.notify_one(); }

    /**
     * @brief Notifies one waiting guest.
     * 
     * This method notifies one of the guests waiting on the guest condition variable,
     * allowing it to proceed if it is waiting on the condition variable.
     */
    void notifyOneGuest() override { guest_.notify_one(); }

    /**
     * @brief Notifies all waiting threads.
     * 
     * This method notifies the host condition variable, waking up the host
     * if it is waiting on the condition variable. It also notifies all guests
     * waiting on the guest condition variable, allowing them to proceed if they
     * are waiting on the condition variable.
     */
    void notifyAll() override {
      host_.notify_one();
      guest_.notify_all();
    }

    /**
     * @brief Checks if there are no guests waiting.
     * 
     * This method returns true if there are no guests currently waiting
     * to access the critical array. Otherwise, it returns false.
     * 
     * @return Bool True if no guests are waiting, false otherwise.
     */
    Bool isNoGuestWaiting() override { return waitingGuests_ == 0; }

  };
} // namespace mbg

#endif // !_MBG_CRITICAL_ARRAY_CONTROLLER_H
