#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X)
  {
      turn = O;
      return turn;
  }

  turn = X;
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location.
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/
Piece TicTacToeBoard::placePiece(int row, int column)
{
    if(getWinner() != Invalid)
    {
        return turn;
    }

    if(row < 0 || column < 0)
    {
        return Invalid;
    }
    else if(row > BOARDSIZE || column > BOARDSIZE)
    {
        return Invalid;
    }

    if(board[row][column] != Blank)
    {
        return board[row][column];
    }

    board[row][column] = turn;

    if(getWinner() == Invalid)
    {
        toggleTurn();
        return turn;
    }
    else
    {
        return turn;
    }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
    if(row < 0 || column < 0)
    {
        return Invalid;
    }
    else if(row > BOARDSIZE || column > BOARDSIZE)
    {
        return Invalid;
    }
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
    //Vertical
    int i = 0;
  for(int j=0; j<BOARDSIZE; j++)
  {
      if(board[i][j] == turn &&
      board[i + 1][j] == turn &&
      board[i + 2][j] == turn)
      {
          return turn;
      }
  }

  //horizontal
  int j = 0;
  for(int i = 0; i < BOARDSIZE; i++)
  {
      if(board[i][j] == turn &&
      board[i][j + 1] == turn &&
      board[i][j + 2] == turn)
      {
          return turn;
      }
  }

  //diagonal Right
  if(board[0][2] == turn &&
  board[1][1] == turn &&
  board[2][0] == turn)
  {
      return turn;
  }

  //diagonal left
  if(board[0][0] == turn &&
  board[1][1] == turn &&
  board[2][2] == turn)
  {
      return turn;
  }

  int blankSpaces = 0;

  for(int i = 0; i < BOARDSIZE; i++)
  {
      for(int j = 0; j < BOARDSIZE; j++)
      {
          if(board[i][j] == Blank)
          {
              blankSpaces++;
          }
      }
  }

  if(blankSpaces == 0)
  {
      return Blank;
  }


  return Invalid;
}
