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