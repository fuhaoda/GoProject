#include <iostream>
#include "tests/tests.h"
#include "core/global.h"
#include <string>
#include "core/timer.h"
#include "DrBombeExplore/benchmarksolutions.h"
int main() {
  /*
  ClockTimer timerun;

  Tests::runBoardIOTests();
  Tests::runBoardBasicTests();
  Tests::runBoardAreaTests();
  auto a = timerun.getSeconds();
*/
  BenchmarkSolutions benchmark;

  benchmark.testBenson();
  //std::string s = Global::trim("   ");
  //std::cout << s;
  return 0;
}
