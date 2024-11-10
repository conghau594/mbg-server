// iServer.h

#ifndef _MBG_I_SERVER_H
#define _MBG_I_SERVER_H

namespace mbg {
  class iServer {
  public:
    virtual ~iServer() = default;
    virtual void run() = 0;
    virtual void exit() = 0;
  };
}

#endif