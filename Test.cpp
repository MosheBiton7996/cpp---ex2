/**
 * Test file written by Avshalom Avraham
 */

#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace ariel;
using namespace std;

Board board;

TEST_CASE("Valid input tests")
{
    Board testBoard;

    //Check different input/outputs with different lengths for exceptions.
    CHECK_NOTHROW(testBoard.post(5, 0, Direction::Vertical, "Test!"));
    CHECK_NOTHROW(testBoard.post(10, 10, Direction::Vertical, "Test!"));
    CHECK_NOTHROW(testBoard.post(0, 300, Direction::Horizontal, "Test!"));
    CHECK_NOTHROW(testBoard.post(0, 10000, Direction::Horizontal, "Test!"));
    CHECK_NOTHROW(testBoard.read(5, 0, Direction::Vertical, 5));
    CHECK_NOTHROW(testBoard.read(10, 10, Direction::Vertical, 2));
    CHECK_NOTHROW(testBoard.read(0, 300, Direction::Horizontal, 0));
    CHECK_NOTHROW(testBoard.read(0, 10000, Direction::Horizontal, 0));

    //Check no exceptions with and without an ad.
    CHECK_NOTHROW(testBoard.read(30, 24, Direction::Horizontal, 5));
    CHECK_NOTHROW(testBoard.post(30, 24, Direction::Horizontal, "Test!"));
    CHECK_NOTHROW(testBoard.read(30, 24, Direction::Horizontal, 5));

    //Check for maximum index.
    CHECK_NOTHROW(testBoard.post(UINT_MAX, 0, Direction::Horizontal, "Test!"));
    CHECK_NOTHROW(testBoard.read(0, UINT_MAX, Direction::Horizontal, 5));
}

TEST_CASE("Post and Read tests from a board")
{
    board.post(0, 0, Direction::Horizontal, "t1");
    CHECK(board.read(0, 0, Direction::Horizontal, 2) == "t1");

    board.post(0, 5, Direction::Horizontal, "t2");
    CHECK(board.read(0, 5, Direction::Horizontal, 2) == "t2");

    board.post(10, 10, Direction::Vertical, "t3");
    CHECK(board.read(10, 10, Direction::Vertical, 2) == "t3");

    board.post(15, 15, Direction::Horizontal, "t4");
    CHECK(board.read(15, 15, Direction::Horizontal, 2) == "t4");

    board.post(2, 2, Direction::Vertical, "t5");
    CHECK(board.read(2, 2, Direction::Vertical, 2) == "t5");

    board.post(20, 20, Direction::Horizontal, "t6");
    CHECK(board.read(20, 20, Direction::Horizontal, 2) == "t6");

    board.post(21, 20, Direction::Vertical, "t7");
    CHECK(board.read(21, 20, Direction::Vertical, 2) == "t7");
}

TEST_CASE("Post and Read tests on used board")
{
    board.post(20, 21, Direction::Vertical, "t8");
    CHECK(board.read(20, 21, Direction::Vertical, 2) == "t8");
    CHECK(board.read(20, 20, Direction::Horizontal, 2) == "tt");

    board.post(45, 45, Direction::Horizontal, "t9");
    CHECK(board.read(45, 45, Direction::Horizontal, 2) == "t9"); 

    board.post(50, 50, Direction::Horizontal, "t10");
    CHECK(board.read(50, 50, Direction::Horizontal, 3) == "t10"); 

    board.post(16, 16, Direction::Vertical, "t11");
    CHECK(board.read(16, 16, Direction::Vertical, 3) == "t11"); 

    board.post(13, 13, Direction::Horizontal, "t12");
    CHECK(board.read(13, 13, Direction::Horizontal, 3) == "t12"); 

    board.post(6, 6, Direction::Vertical, "t13");
    CHECK(board.read(6, 6, Direction::Vertical, 3) == "t13");
}
