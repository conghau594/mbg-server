// iState.h

#ifndef _MBG_I_STATE_H
#define _MBG_I_STATE_H

namespace mbg {
  class iState {
  public:
    virtual ~iState() = default;
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
  };
}

#endif