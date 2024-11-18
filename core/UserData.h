//UserData.h
#ifndef _MBG_USER_DATA_H
#define _MBG_USER_DATA_H

#include "ExtendedType.h"
#include "DataObject.h"

namespace mbg {
  class UserData final : public DataObject {
    ExStr  loginSID_;
    String userID_;
    String clientCode_;

  public:
    UserData() : DataObject(OBJ_USER_DATA) { }
    UserData(const String& userID, const ExStr& loginSID, const String& clientCode)
      : DataObject(OBJ_USER_DATA), userID_(userID),
        loginSID_(loginSID), clientCode_(clientCode) 
    {}

    const String& getUserID() const { return userID_; }
    const ExStr& getLoginSID() const { return loginSID_; }
    const String& getClientCode() const { return clientCode_; }

    void setLoginSID(const ExStr& loginSID) { loginSID_ = loginSID; }

    constexpr static int TYPE_ID = OBJ_USER_DATA;
  };
} // namespace mbg

#endif // !_MBG_USER_DATA_H

