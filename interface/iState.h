#ifndef _MBG_ISTATE_H
#define _MBG_ISTATE_H

namespace mbg {
  class iState {
  public:
    virtual ~iState() = default;
    virtual void onEnter() = 0;
    virtual void onExit() = 0; 
  }
}

#endif