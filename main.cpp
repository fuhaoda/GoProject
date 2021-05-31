#include <iostream>
#include "tests/tests.h"
#include "core/global.h"
#include <string>
#include "core/timer.h"
#include "DrBombeExplore/benchmarksolutions.h"
#include "DrBombeExplore/sgfgamesummary.h"

int main() {
  /*
  ClockTimer timerun;

  Tests::runBoardIOTests();
  Tests::runBoardBasicTests();
  Tests::runBoardAreaTests();
  auto a = timerun.getSeconds();

  auto sgfFilesReader = SGFFilesReader("/Users/haodafu/Documents/Files/Temp/katagomatch/0409sgfs");
  // auto sgfFilesReader = SGFFilesReader("/Users/haodafu/Documents/CodeDev/KataGo/cpp/docs/9x9matches");
  // sgfFilesReader.splitSGFFilesIntoSingleSgfGameFile("/Users/haodafu/Documents/Files/Temp/9x9KataGoGames", "9x9_");
  sgfFilesReader.winningRate();


*/
  BenchmarkSolutions benchmark;

  benchmark.testBenson();
  //std::string s = Global::trim("   ");
  //std::cout << s;
  return 0;
}
