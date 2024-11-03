#ifndef _MBG_ISERVER_H
#define _MBG_ISERVER_H

namespace mbg {
  class iServer {
  public:
    virtual ~iServer() = default;
    virtual void run() = 0;
    virtual void exit() = 0; 
  }
}

#endif