/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggleTurn)
{
    TicTacToeBoard board;
    Piece player = board.toggleTurn();
    ASSERT_EQ(player, O);
}

TEST(TicTacToeBoardTest, toggleTurnAgain)
{
    TicTacToeBoard board;
    Piece player = board.toggleTurn();
    player = board.toggleTurn();
    ASSERT_EQ(player, X);
}

TEST(TicTacToeBoardTest, tieGame)
{
    TicTacToeBoard board;
    board.placePiece(0,0);
    board.placePiece(0,1);
    board.placePiece(1,1);
    board.placePiece(2,2);
    board.placePiece(2,0);
    board.placePiece(0,2);
    board.placePiece(1,2);
    board.placePiece(1,0);
    board.placePiece(2,1);

    ASSERT_EQ(board.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, boardDraw)
{
    TicTacToeBoard board;
    board.placePiece(0,0);
    board.placePiece(0,1);
    board.placePiece(1,1);
    board.placePiece(2,2);
    board.placePiece(2,0);
    board.placePiece(0,2);
    board.placePiece(1,2);
    board.placePiece(1,0);
    board.placePiece(2,1);

    ASSERT_EQ(board.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, placepieceOutOfBounds)
{
    TicTacToeBoard board;

    ASSERT_EQ(board.placePiece(0,9), Invalid);
}

TEST(TicTacToeBoardTest, getpieceOutOfBounds)
{
    TicTacToeBoard board;

    ASSERT_EQ(board.getPiece(0,9), Invalid);
}

TEST(TicTacToeBoardTest, startGameWinner)
{
    TicTacToeBoard board;

    ASSERT_EQ(board.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, verticalWinnerX)
{
    TicTacToeBoard board;
    board.placePiece(0,0);
    board.placePiece(0,1);
    board.placePiece(1,0);
    board.placePiece(1,1);
    board.placePiece(2,0);

    ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, verticalWinnerO)
{
    TicTacToeBoard board;
    board.placePiece(0,0);
    board.placePiece(0,1);
    board.placePiece(1,0);
    board.placePiece(1,1);
    board.placePiece(0,2);
    board.placePiece(2,1);

    ASSERT_EQ(board.getWinner(), O);
}

TEST(TicTacToeBoardTest, horizontalWinnerX)
{
    TicTacToeBoard board;
    board.placePiece(0,0);
    board.placePiece(1,0);
    board.placePiece(0,1);
    board.placePiece(1,1);
    board.placePiece(0,2);

    ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, horizontalWinnerO)
{
    TicTacToeBoard board;
    board.placePiece(0,0);
    board.placePiece(1,0);
    board.placePiece(0,1);
    board.placePiece(1,1);
    board.placePiece(2,2);
    board.placePiece(1,2);

    ASSERT_EQ(board.getWinner(), O);
}

TEST(TicTacToeBoardTest, diagLeftWinnerX)
{
    TicTacToeBoard board;
    board.placePiece(0,0);
    board.placePiece(1,0);
    board.placePiece(1,1);
    board.placePiece(1,2);
    board.placePiece(2,2);

    ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, diagLeftWinnerO)
{
    TicTacToeBoard board;
    board.placePiece(0,1);
    board.placePiece(0,0);
    board.placePiece(0,2);
    board.placePiece(1,1);
    board.placePiece(1,2);
    board.placePiece(2,2);

    ASSERT_EQ(board.getWinner(), O);
}

TEST(TicTacToeBoardTest, diagRightWinnerX)
{
    TicTacToeBoard board;
    board.placePiece(0,2);
    board.placePiece(1,0);
    board.placePiece(1,1);
    board.placePiece(1,2);
    board.placePiece(2,0);

    ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, diagRightWinnerO)
{
    TicTacToeBoard board;
    board.placePiece(0,1);
    board.placePiece(0,2);
    board.placePiece(1,2);
    board.placePiece(1,1);
    board.placePiece(1,0);
    board.placePiece(2,0);

    ASSERT_EQ(board.getWinner(), O);
}
