//UserData.h
#ifndef _MBG_USER_DATA_H
#define _MBG_USER_DATA_H

#include "ExtendedType.h"

namespace mbg {
  class UserData {
    ExStr  loginSID_;
    String userID_;
    String clientCode_;

  public:
    UserData() = default;
    UserData(const String& userID, const ExStr& loginSID, const String& clientCode)
      : userID_(userID), loginSID_(loginSID), clientCode_(clientCode) {}

    const String& getUserID() const { return userID_; }
    const ExStr& getLoginSID() const { return loginSID_; }
    const String& getClientCode() const { return clientCode_; }

    void setLoginSID(const ExStr& loginSID) { loginSID_ = loginSID; }

  };
} // namespace mbg

#endif // !_MBG_USER_DATA_H

