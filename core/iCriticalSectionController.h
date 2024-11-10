//iCriticalSectionController.h

#ifndef _MBG_I_CRITICAL_SECTION_CONTROLLER_H
#define _MBG_I_CRITICAL_SECTION_CONTROLLER_H

#include "basetypes.h"

namespace mbg {
  class iCriticalSectionController {
  public:
    virtual ~iCriticalSectionController() = default;
    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual void wakeUpOwner() = 0;
    virtual void notifyOneSender() = 0;
    virtual Bool isNoSenderWaiting() = 0;
  };
} // namespace mbg

#endif
