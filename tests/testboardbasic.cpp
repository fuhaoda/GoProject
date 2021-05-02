#include "../tests/tests.h"

using namespace std;
using namespace TestCommon;

/*
for a 2x2 board, it lays as below. size = 2,  (size+1)*(size+2)+1 = 3*4+1 = 13 items.
0  1  2  3
3  4  5  6
6  7  8  9
9 10 11 12
*/

void Tests::runBoardIOTests() {
  cout << "Running board IO tests" << endl;
  ostringstream out;

  //============================================================================
  {
    const char* name = "Location parse test";
    auto testLoc = [&out](const char* s, int xSize, int ySize) {
      try {
        Loc loc = Location::ofString(s,xSize,ySize);
        out << s << " " << Location::toString(loc,xSize,ySize) << " x " << Location::getX(loc,xSize) << " y " << Location::getY(loc,xSize) << endl;
      }
      catch(const StringError& e) {
        out << e.what() << endl;
      }
    };

    constexpr int numSizes = 4;
    int sizes[numSizes] = {9,19,26,70};
    for(int i = 0; i<numSizes; i++) {
      for(int j = 0; j<numSizes; j++) {
        if(i-j > 1 || j-i > 1)
          continue;
        int xSize = sizes[i];
        int ySize = sizes[j];
        out << "----------------------------------" << endl;
        out << xSize << " " << ySize << endl;

        testLoc("A1",xSize,ySize);
        testLoc("A0",xSize,ySize);
        testLoc("B2",xSize,ySize);
        testLoc("b2",xSize,ySize);
        testLoc("A",xSize,ySize);
        testLoc("B",xSize,ySize);
        testLoc("1",xSize,ySize);
        testLoc("pass",xSize,ySize);
        testLoc("H9",xSize,ySize);
        testLoc("I9",xSize,ySize);
        testLoc("J9",xSize,ySize);
        testLoc("J10",xSize,ySize);
        testLoc("K8",xSize,ySize);
        testLoc("k19",xSize,ySize);
        testLoc("a22",xSize,ySize);
        testLoc("y1",xSize,ySize);
        testLoc("z1",xSize,ySize);
        testLoc("aa1",xSize,ySize);
        testLoc("AA26",xSize,ySize);
        testLoc("AZ26",xSize,ySize);
        testLoc("BC50",xSize,ySize);
      }
    }

    string expected = R"%%(
----------------------------------
9 9
A1 A1 x 0 y 8
Could not parse board location: A0
B2 B2 x 1 y 7
b2 B2 x 1 y 7
Could not parse board location: A
Could not parse board location: B
Could not parse board location: 1
pass pass x 0 y -1
H9 H9 x 7 y 0
Could not parse board location: I9
J9 J9 x 8 y 0
Could not parse board location: J10
Could not parse board location: K8
Could not parse board location: k19
Could not parse board location: a22
Could not parse board location: y1
Could not parse board location: z1
Could not parse board location: aa1
Could not parse board location: AA26
Could not parse board location: AZ26
Could not parse board location: BC50
----------------------------------
9 19
A1 A1 x 0 y 18
Could not parse board location: A0
B2 B2 x 1 y 17
b2 B2 x 1 y 17
Could not parse board location: A
Could not parse board location: B
Could not parse board location: 1
pass pass x 0 y -1
H9 H9 x 7 y 10
Could not parse board location: I9
J9 J9 x 8 y 10
J10 J10 x 8 y 9
Could not parse board location: K8
Could not parse board location: k19
Could not parse board location: a22
Could not parse board location: y1
Could not parse board location: z1
Could not parse board location: aa1
Could not parse board location: AA26
Could not parse board location: AZ26
Could not parse board location: BC50
----------------------------------
19 9
A1 A1 x 0 y 8
Could not parse board location: A0
B2 B2 x 1 y 7
b2 B2 x 1 y 7
Could not parse board location: A
Could not parse board location: B
Could not parse board location: 1
pass pass x 0 y -1
H9 H9 x 7 y 0
Could not parse board location: I9
J9 J9 x 8 y 0
Could not parse board location: J10
K8 K8 x 9 y 1
Could not parse board location: k19
Could not parse board location: a22
Could not parse board location: y1
Could not parse board location: z1
Could not parse board location: aa1
Could not parse board location: AA26
Could not parse board location: AZ26
Could not parse board location: BC50
----------------------------------
19 19
A1 A1 x 0 y 18
Could not parse board location: A0
B2 B2 x 1 y 17
b2 B2 x 1 y 17
Could not parse board location: A
Could not parse board location: B
Could not parse board location: 1
pass pass x 0 y -1
H9 H9 x 7 y 10
Could not parse board location: I9
J9 J9 x 8 y 10
J10 J10 x 8 y 9
K8 K8 x 9 y 11
k19 K19 x 9 y 0
Could not parse board location: a22
Could not parse board location: y1
Could not parse board location: z1
Could not parse board location: aa1
Could not parse board location: AA26
Could not parse board location: AZ26
Could not parse board location: BC50
----------------------------------
19 26
A1 A1 x 0 y 25
Could not parse board location: A0
B2 B2 x 1 y 24
b2 B2 x 1 y 24
Could not parse board location: A
Could not parse board location: B
Could not parse board location: 1
pass pass x 0 y -1
H9 H9 x 7 y 17
Could not parse board location: I9
J9 J9 x 8 y 17
J10 J10 x 8 y 16
K8 K8 x 9 y 18
k19 K19 x 9 y 7
a22 A22 x 0 y 4
Could not parse board location: y1
Could not parse board location: z1
Could not parse board location: aa1
Could not parse board location: AA26
Could not parse board location: AZ26
Could not parse board location: BC50
----------------------------------
26 19
A1 A1 x 0 y 18
Could not parse board location: A0
B2 B2 x 1 y 17
b2 B2 x 1 y 17
Could not parse board location: A
Could not parse board location: B
Could not parse board location: 1
pass pass x 0 y -1
H9 H9 x 7 y 10
Could not parse board location: I9
J9 J9 x 8 y 10
J10 J10 x 8 y 9
K8 K8 x 9 y 11
k19 K19 x 9 y 0
Could not parse board location: a22
y1 Y1 x 23 y 18
z1 Z1 x 24 y 18
aa1 AA1 x 25 y 18
Could not parse board location: AA26
Could not parse board location: AZ26
Could not parse board location: BC50
----------------------------------
26 26
A1 A1 x 0 y 25
Could not parse board location: A0
B2 B2 x 1 y 24
b2 B2 x 1 y 24
Could not parse board location: A
Could not parse board location: B
Could not parse board location: 1
pass pass x 0 y -1
H9 H9 x 7 y 17
Could not parse board location: I9
J9 J9 x 8 y 17
J10 J10 x 8 y 16
K8 K8 x 9 y 18
k19 K19 x 9 y 7
a22 A22 x 0 y 4
y1 Y1 x 23 y 25
z1 Z1 x 24 y 25
aa1 AA1 x 25 y 25
AA26 AA26 x 25 y 0
Could not parse board location: AZ26
Could not parse board location: BC50
----------------------------------
26 70
A1 A1 x 0 y 69
Could not parse board location: A0
B2 B2 x 1 y 68
b2 B2 x 1 y 68
Could not parse board location: A
Could not parse board location: B
Could not parse board location: 1
pass pass x 0 y -1
H9 H9 x 7 y 61
Could not parse board location: I9
J9 J9 x 8 y 61
J10 J10 x 8 y 60
K8 K8 x 9 y 62
k19 K19 x 9 y 51
a22 A22 x 0 y 48
y1 Y1 x 23 y 69
z1 Z1 x 24 y 69
aa1 AA1 x 25 y 69
AA26 AA26 x 25 y 44
Could not parse board location: AZ26
Could not parse board location: BC50
----------------------------------
70 26
A1 A1 x 0 y 25
Could not parse board location: A0
B2 B2 x 1 y 24
b2 B2 x 1 y 24
Could not parse board location: A
Could not parse board location: B
Could not parse board location: 1
pass pass x 0 y -1
H9 H9 x 7 y 17
Could not parse board location: I9
J9 J9 x 8 y 17
J10 J10 x 8 y 16
K8 K8 x 9 y 18
k19 K19 x 9 y 7
a22 A22 x 0 y 4
y1 Y1 x 23 y 25
z1 Z1 x 24 y 25
aa1 AA1 x 25 y 25
AA26 AA26 x 25 y 0
AZ26 AZ26 x 49 y 0
Could not parse board location: BC50
----------------------------------
70 70
A1 A1 x 0 y 69
Could not parse board location: A0
B2 B2 x 1 y 68
b2 B2 x 1 y 68
Could not parse board location: A
Could not parse board location: B
Could not parse board location: 1
pass pass x 0 y -1
H9 H9 x 7 y 61
Could not parse board location: I9
J9 J9 x 8 y 61
J10 J10 x 8 y 60
K8 K8 x 9 y 62
k19 K19 x 9 y 51
a22 A22 x 0 y 48
y1 Y1 x 23 y 69
z1 Z1 x 24 y 69
aa1 AA1 x 25 y 69
AA26 AA26 x 25 y 44
AZ26 AZ26 x 49 y 44
BC50 BC50 x 52 y 20
)%%";
    expect(name,out,expected);
  }


  //============================================================================
  {
    const char* name = "Parse test";
    Board::initHash();
    Board board = Board::parseBoard(6,5,R"%%(
 ABCDEF
5......
4......
3......
2......
1......
)%%");
    Board board2 = Board::parseBoard(6,5,R"%%(
   A B C D E F
10 . . . . . .
 9 . . . . . .
 8 . . . . . .
 7 . X . . . .
 6 . . . . . .
)%%");

    board.playMove(Location::ofString("B2",board),P_BLACK,true);
    board2.playMove(Location::ofString("F1",board),P_WHITE,true);
    out << board << endl;
    out << board2 << endl;

    string expected = R"%%(
HASH: 27902CF3F972B1855303DB453BF8DE63
   A B C D E F
 5 . . . . . .
 4 . . . . . .
 3 . . . . . .
 2 . X . . . .
 1 . . . . . .


HASH: BC864FD8F525EE9D6B590472C800841A
   A B C D E F
 5 . . . . . .
 4 . . . . . .
 3 . . . . . .
 2 . X . . . .
 1 . . . . . O

)%%";

    expect(name,out,expected);
  }
}


