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

  void f() { }

  class B {
    int y_;
  public:
    B(const A& a) : y_(a.x_) {}
  };
};

class C : public A {
  int z_;
public:
  C(int x, int z) : A(x), z_(z) {}
  void f() { }

};

void f(A*& a) {
  a = new C(10, 11);
}
void f2(A** a) {
  *a = new C(10, 11);
}
#include "core/Json.h"
#include <fstream>

template<typename... DATA_TYPES>
class TEST {
  std::tuple<DATA_TYPES...> data_;
public:
  TEST(DATA_TYPES... args) : data_(args...) {}


  template<size_t I>
  std::tuple_element<I, std::tuple<DATA_TYPES...>>::type& get() {
    return std::get<I>(data_);
  }

};

enum {
  USER_DATA,
  CHESS_GAME_DATA
};

struct UserData {
  int id_;
  std::string name_;
};

struct GameData {
  int id_;
  std::string name_;
};


int main()
{
  TEST<int, float, std::string> t(12, -4.1, "awor");
  using TESTIFS = TEST<int, float, std::string>;


  //int* i = t.getData<int>();
  t.get<0>() = 10;
  t.get<1>() = 10.0f;
  t.get<2>() = "10";

  
  UserData* userData = new UserData{ 1, "John" };
  GameData* gameData = new GameData{ 1, "Chess" };

  TEST<UserData*, GameData*> t2(userData, gameData);
  t2.get<USER_DATA>()->name_ = "John Doe";
  t2.get<CHESS_GAME_DATA>()->name_ = "Chess Master";



  return 0;
}