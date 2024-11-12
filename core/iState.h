// iState.h

#ifndef _MBG_I_STATE_H
#define _MBG_I_STATE_H

namespace mbg {
  /**
   * @brief Interface for state management.
   *
   * The iState class provides a common interface for states in a state machine.
   * Any class that inherits from iState must implement the onEnter and onExit methods.
   */
  class iState {
  public:
    virtual ~iState() = default;

    /**
     * @brief This method is called when the state is entered.
     * It must be overridden by any class that inherits from iState.
     */
    virtual void onEnter() = 0;

    /**
     * @brief This method is called when the state is exited.
     * It must be overridden by any class that inherits from iState.
     */
    virtual void onExit() = 0;
  };
} // namespace mbg

#endif // !_MBG_I_STATE_H