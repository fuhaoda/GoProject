#ifndef TESTS_H
#define TESTS_H

#include <sstream>

#include "../core/global.h"
#include "../core/rand.h"
#include "../core/test.h"
#include "../game/board.h"
#include "../game/rules.h"
#include "../game/boardhistory.h"


namespace Tests {
  //testboardbasic.cpp

  void runBoardIOTests();
  void runBoardBasicTests();
  void runBoardHandicapTest();
  void runBoardUndoTest();
  void runBoardStressTest();

  void runBoardAreaTests();
}

namespace TestCommon {
  bool boardsSeemEqual(const Board& b1, const Board& b2);
  std::string getBenchmarkSGFData(int boardSize);

  void overrideForOpenCL(bool& inputsNHWC, bool& useNHWC);
}

#endif
