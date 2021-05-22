//
// Created by Haoda Fu on 5/21/21.
//

#include "benchmarksolutions.h"
#include "../core/timer.h"
#include "../dataio/sgf.h"
#include "sgfgamesummary.h"
#include "../tests/tests.h"
using namespace TestCommon;

void BenchmarkSolutions::testBenson() {
  auto sgfFilesReader = SGFFilesReader("/Users/haodafu/Documents/Files/Temp/katagomatch/benchmarkdata");
  size_t totalGameTest = 1;

  auto calAreas = [](const Board& board, Color result[Board::MAX_ARR_SIZE]) ->int64_t{
    int64_t res = 0;
    bool safeBigTerritoriesBuf[4] =        {false, true,  true,  true};
    bool unsafeBigTerritoriesBuf[4] =      {false, false, true,  true};
    bool nonPassAliveStonesBuf[4] =        {false, false, false, true};

    for(int mode = 0; mode < 8; mode++) {
      bool multiStoneSuicideLegal = (mode % 2 == 1);
      bool safeBigTerritories = safeBigTerritoriesBuf[mode/2];
      bool unsafeBigTerritories = unsafeBigTerritoriesBuf[mode/2];
      bool nonPassAliveStones = nonPassAliveStonesBuf[mode/2];
      Board copy(board);
      copy.calculateArea(result,nonPassAliveStones,safeBigTerritories,unsafeBigTerritories,multiStoneSuicideLegal);
      for(int y = 0; y<copy.y_size; y++) {
        for(int x = 0; x<copy.x_size; x++) {
          Loc loc = Location::getLoc(x,y,copy.x_size);
          res+=result[loc];
        }
      }
      testAssert(boardsSeemEqual(copy,board));
      copy.checkConsistency();
    }
    return res;
  };

  Color result[Board::MAX_ARR_SIZE];
  Board::initHash();
  int64_t total =0;

  ClockTimer timeMyCode;
  for(size_t gameID =0; gameID< totalGameTest; ++gameID){
    auto currentSGF = sgfFilesReader.getGameSgf(gameID);
    auto sgf = Sgf::parse(currentSGF);
    auto xySize = sgf->getXYSize();
    std::vector<Move> moves;
    sgf->getMoves(moves, xySize.x, xySize.y);
    for(size_t iter=0; iter<totalIter; ++iter){
      Board board(xySize.x,xySize.y);
      for(auto & move : moves) {
        board.setStone(move.loc,move.pla);
        total+= iter + gameID + calAreas(board, result);
      }
    }
  }
  std::cout << "Total value:" << total << std::endl;
  std::cout << "Total time in seconds: " << timeMyCode.getSeconds() << std::endl;
}

