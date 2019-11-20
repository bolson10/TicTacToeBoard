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

TEST(TicTacToeBoardTest, if_toggleTurn_changes_X_to_O)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.toggleTurn(),O);
}

TEST(TicTacToeBoardTest, if_toggleTurn_changes_O_to_X)
{
	TicTacToeBoard board;
	board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(),X);
}

TEST(TicTacToeBoardTest, if_toggleTurn_handles_many_turn_switches)
{
	TicTacToeBoard board;
	board.toggleTurn();
	board.toggleTurn();
	board.toggleTurn();
	board.toggleTurn();
	board.toggleTurn();
	board.toggleTurn();
	board.toggleTurn();
	board.toggleTurn();
	board.toggleTurn();
	board.toggleTurn();
	board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(),X);
}

TEST(TicTacToeBoardTest, if_placePiece_inserts_piece_on_empty_space)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,0),X);
}

TEST(TicTacToeBoardTest, if_placePiece_inserts_piece_on_empty_space_after_toggleTurn)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.placePiece(0,1),O);
}

TEST(TicTacToeBoardTest, if_placePiece_detects_piece_already_at_position)
{
	TicTacToeBoard board;
	board.placePiece(0,2);
	ASSERT_EQ(board.placePiece(0,2),X);
}

TEST(TicTacToeBoardTest, if_placePiece_detects_position_out_of_bounds)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(3,3),Invalid);
}

TEST(TicTacToeBoardTest, if_placePiece_detects_board_is_filled)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(1,0);
	board.placePiece(1,1);
	board.placePiece(1,2);
	board.placePiece(2,0);
	board.placePiece(2,1);
	ASSERT_EQ(board.placePiece(2,2),Blank);
}