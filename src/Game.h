#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Well.h"
#include "Piece.h"
#include "UserInterface.h"
#include <string>

enum SpecialControls
{
	QUIT,
	SPACEBAR,
	DOWN,
	NORMAL,
	NOTHING
};

class Game
{
public:
	Game(int width, int height);
	void play();
	// Plays a game of Chetyris.

private:
	// Class invariant:
	//	m_well is the well of width and height passed by the user to the Game constructor
	//	m_screen is the screen that the user sees
	//	m_level > 1
	//	m_score >= 0
	//	m_rowsLeft is 5 * m_level, at the start of each level. m_rowsLeft >= 0

	Well m_well;
	Screen m_screen;
	int m_level;
	int m_score;
	int m_rowsLeft;

	// Helper functions
	bool playOneLevel();
	void displayPrompt(std::string s);
	void displayStatus(PieceType nextPiece = NONE);
	void updateStats(int rowsVaporized);
	void printNextPiece(PieceType nextPiece);
	void printRightJustified(int stat, int x, int y);
	bool pieceInPlay(PieceType current);
	// Returns false if the player quits the game.
	SpecialControls controls(char move, PieceType current);
};

#endif // GAME_INCLUDED