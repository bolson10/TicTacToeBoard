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
  legal_turn_count = 0;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X)
  	turn=O;
  else
  	turn=X;
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
  if(legal_turn_count >= BOARDSIZE*BOARDSIZE)
  	return Blank;
  Piece cur_piece = turn;
  if(row < 0 || row >  (BOARDSIZE-1) || column < 0 || column > (BOARDSIZE-1))
  	cur_piece = Invalid;
  else if(board[row][column] == Blank)
  {
  	legal_turn_count += 1;
  	board[row][column] = cur_piece;
  }
  else if(board[row][column] == X || board[row][column] == O)
  	cur_piece = board[row][column];
  turn = toggleTurn();
  return cur_piece;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row < 0 || row >  (BOARDSIZE-1) || column < 0 || column > (BOARDSIZE-1))
  	return Invalid;
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  if(legal_turn_count != 9)
  	return Invalid;
  for(int i=0; i < BOARDSIZE; i++)
  {
  	for(int j=0; j < BOARDSIZE; j++)
  	{
  		Piece pc = board[i][j];
  		if(j==0)
  		{
  		bool threeHorizontal = true;
  		for(int k=j; k < BOARDSIZE; k++)
  		{
  			if(board[i][k] != pc)
  				threeHorizontal = false;
  		}
  		if(threeHorizontal)
  			return pc;
  	    }
  	    if(i==0)
  	    {
  	    bool threeVertical = true;	
  		for(int k=i; k < BOARDSIZE; k++)
  		{
  			if(board[k][j] != pc)
  				threeVertical = false;
  		}
  		if(threeVertical)
  			return pc;  	
  	    }
  	    if(i==0 && j==0)
  	    {
  	    bool threeDiagonal = true;
  	    for(int k=i; k < BOARDSIZE-1;k++)
  	    {
  	    	int l=k;
  	    	if(board[k+1][l+1] != pc)
  	    		threeDiagonal = false;
  	    }
  	    if(threeDiagonal)
  	    	return pc;	
  	    } 
  	    if(i==0 && j==2) 
  	    {
  	    	bool threeDiagonal2 = true;
  	    	int l = i;
  	    	for(int k=j; k > 0; k--)
  	    	{
  	    		if(board[l+1][k-1] != pc)
  	    			threeDiagonal2 = false;
  	    		l += 1;
  	    	}
  	    if(threeDiagonal2)
  	    	return pc;
  	    }
  	}
  }
  return Blank;
}
