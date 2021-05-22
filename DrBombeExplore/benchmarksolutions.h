//
// Created by Haoda Fu on 5/21/21.
//

#ifndef GOPROJECT_DRBOMBEEXPLORE_BENCHMARKSOLUTIONS_H_
#define GOPROJECT_DRBOMBEEXPLORE_BENCHMARKSOLUTIONS_H_

#include <iostream>


class BenchmarkSolutions {
 public:
  void setTotalIter(size_t);
  size_t getTotalIter() const;
  void testBenson();
 private:
  std::size_t totalIter{100};
};

#endif //GOPROJECT_DRBOMBEEXPLORE_BENCHMARKSOLUTIONS_H_
