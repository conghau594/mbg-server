#include "core/ExtendedType.h"
#include "core/DataField.h"
#include <iostream>
#include <cassert>

using namespace mbg;
using namespace std;

class A {
  int x_;
public:
  A(int x) : x_(x) {}
  class B {
    int y_;
  public:
    B(const A& a) : y_(a.x_) {}
  };
};

#include "core/Json.h"
#include <fstream>


int main()
{
  fstream file("test.txt", ios::in);
  size_t size = file.tellg();
  string s(1000, ' ');
  file.read(s.data(), 1000);

  char t[] = "{ \"x\" : \"The quick brown fox jumps over the lazy dog.\"}";
  char* s_stdstring = t;
  
  try {
    Json j_stdstring(Json::parse(s));
    std::cout << setw(2) << j_stdstring << "\n\n";
    std::cout << j_stdstring["x"].get<std::string>() << "\n\n";
  }
  catch (Json::exception e) {
    std::cout << "\n" << e.what();
  }


  std::cout << PATH_TAG.getFieldName() << std::endl;

  ExInt x1();
  ExInt x2(19);
  ExStr x3("abd");
  ExStr x4();


  return 0;
}