//Mutex.h

#ifndef _MBG_MUTEX_H
#define _MBG_MUTEX_H

#include <mutex>

namespace mbg {
  using Mutex = std::mutex;                        ///< Mutex type alias. 
  using UniqueLock = std::unique_lock<std::mutex>; ///< Unique lock type alias.
  using LockGuard = std::lock_guard<std::mutex>;   ///< Lock guard type alias.
} // namespace mbg 

#endif // !_MBG_MUTEX_H
