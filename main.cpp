#include "core/Server.h"
#include <iostream>
#include <cassert>

using namespace mbg;
using namespace std;

//#include "Json.h"

int main()
{
  


  iServer& server = *(new Server());
  server.run();


  delete &server;

  return 0;
}