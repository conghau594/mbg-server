//iCriticalSectionController.h

#ifndef _MBG_I_CRITICAL_ARRAY_CONTROLLER_H
#define _MBG_I_CRITICAL_ARRAY_CONTROLLER_H

#include "primitives.h"

namespace mbg {
  /**
   * @brief Interface for controlling critical sections.
   * 
   * This interface provides methods for locking and unlocking critical sections,
   * waking up the host (the container containing the critical section), notifying 
   * guests, and checking if no guests are waiting.
   * Derived classes must implement all the methods defined in this interface.
   */
  class iCriticalArrayController {
  public:
    virtual ~iCriticalArrayController () = default;

    /**
     * @brief Locks the critical section for the host.
     * 
     * This method should be called to lock the critical section for the host.
     * Must be implemented by derived classes.
     */
    virtual void lockForHost() = 0;

    /**
     * @brief Locks the critical section for a guest.
     * 
     * This method should be called to lock the critical section for a guest.
     * Must be implemented by derived classes.
     */
    virtual void lockForGuest() = 0;

    /**
     * @brief Unlocks the critical section.
     * 
     * This method should be called to unlock the critical section.
     * Must be implemented by derived classes.
     */
    virtual void unlock() = 0;

    /**
     * @brief Wakes up the host, that is the container containing the critical section.
     * This method should be called to wake up the host.
     * Must be implemented by derived classes.
     */
    virtual void wakeUpHost() = 0;


    /**
     * @brief Notifies one guest waiting on the critical section.
     * This method should be called to notify a single guest that is waiting.
     * Must be implemented by derived classes.
     */
    virtual void notifyOneGuest() = 0;

    /**
     * @brief Notifies all guests and also the host waiting on the critical section.
     * This method should be called to notify all guests and the host that are waiting.
     * Must be implemented by derived classes.
     */
    virtual void notifyAll() = 0;

    /**
     * @brief Checks if no guest is waiting on the critical section.
     * This method should be called to determine if there are no guests waiting.
     * Must be implemented by derived classes.
     * 
     * @return Bool True if no guest is waiting, otherwise false.
     */
    virtual Bool isNoGuestWaiting() = 0;
  };
} // namespace mbg

#endif // !_MBG_I_CRITICAL_ARRAY_CONTROLLER_H
