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

TEST(TicTacToeBoard, boardExtraPiecePlaced)
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

    ASSERT_EQ(board.placePiece(0,0), Invalid);
}

TEST(TicTacToeBoard, boardDraw)
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

Test(TicTacToeBoard, placepieceOutOfBounds)
{
    TicTacToeBoard board;

    ASSERT_EQ(board.placePiece(0,9), Invalid);
}

TEST(TicTacToeBoard, getpieceOutOfBounds)
{
    TicTacToeBoard board;

    ASSERT_EQ(board.getPiece(0,9), Invalid);
}

TEST(TicTacToeBoard, startGameWinner)
{
    TicTacToeBoard board;

    ASSERT_EQ(board.getWinner(), Invalid);
}

TEST(TicTacToeBoard, verticalWinnerX)
{
    TicTacToeBoard board;
    board.placePiece(0,0);
    board.placePiece(0,1);
    board.placePiece(1,0);
    board.placePiece(1,1);
    board.placePiece(2,0);

    ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoard, verticalWinnerO)
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
