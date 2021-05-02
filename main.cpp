#include <iostream>
#include "tests/tests.h"
#include "core/global.h"
#include <string>

int main() {
  Tests::runBoardIOTests();
  //std::string s = Global::trim("   ");
  //std::cout << s;
  return 0;
}
