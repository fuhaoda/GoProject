cmake_minimum_required(VERSION 3.10.2)
project(GoProject)

set(CMAKE_CXX_STANDARD 17)

include_directories(external)
include_directories(external/tclap-1.2.2/include)
include_directories(SYSTEM external/filesystem-1.3.6/include) #SYSTEM suppresses a few warnings

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.18.0")
    # Suppress a warning message for setting cuda flags that still works fine for now
    cmake_policy(SET CMP0104 OLD)
endif()

if(APPLE)
    # Fix linking on 10.14+. See https://stackoverflow.com/questions/54068035
    include_directories(/usr/local/include)
    link_directories(/usr/local/lib)
endif()

add_executable(GoProject
        core/global.cpp
        core/bsearch.cpp
        core/config_parser.cpp
        core/datetime.cpp
        core/elo.cpp
        core/fancymath.cpp
        core/hash.cpp
        core/logger.cpp
        core/makedir.cpp
        core/md5.cpp
        core/multithread.cpp
        core/rand.cpp
        core/rand_helpers.cpp
        core/sha2.cpp
        core/test.cpp
        core/threadsafequeue.cpp
        core/timer.cpp
        game/board.cpp
        game/rules.cpp
        game/boardhistory.cpp
        dataio/sgf.cpp
        tests/testcommon.cpp
        tests/testboardbasic.cpp
        tests/testboardarea.cpp
        DrBombeExplore/sgfgamesummary.cpp
        main.cpp DrBombeExplore/benchmarksolutions.cpp)