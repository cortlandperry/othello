#include "player.hpp"
#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;

/*
*	This is a minor change so that I get github to be working.
*
*
*/

// this is Alex practicing commit



/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) 
{
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    color = side;	//side that the player is on
    playerboard = new Board();	//board that I deal with
}

/*
 * Destructor for the player.
 */
Player::~Player() 
{
}



/*
 * Helper Function: Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. Must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::heuristicPlayer(Move *opponentsMove, int msLeft) 
{
	// make the opposing player's move on the board
	if (color == WHITE)
	{
		playerboard->doMove(opponentsMove, BLACK);
	}
	else
	{
		playerboard->doMove(opponentsMove, WHITE);
	}
	

	// now calculate the AI's move
	vector<Move*> array;
	int desiredmove = 0;
	int maxscore;
	
	// base case if there are no valid moves for the AI
	if(playerboard->hasMoves(color) == false)
	{
		return nullptr;
	}
	
	//creating the array of valid moves
	else
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++) 
			{
				Move * move = new Move(i, j);         	
            	if (playerboard->checkMove(move, color))
            	{
            		array.push_back(move);
            	}
        	}
    	}

    	// This is the code for our heuristic and beating simpleplayer
    	maxscore = playerboard->getMoveScore(array[0], color);
    	for (unsigned int i = 0; i < array.size(); i++)
    	{
    		if (playerboard->getMoveScore(array[i], color) > maxscore)
    		{
    			desiredmove = i;
    			maxscore = playerboard->getMoveScore(array[i], color);
    		}
    	}
    	playerboard->doMove(array[desiredmove], color);
    	return array[desiredmove];
	}
}
	
	
/*
 * Calculate the score of a move after simulating a move made by the
 * WHITE AI.
 * @Param: The move to be made by the WHITE AI.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) 
{
	/*
	 * This was here for when I made the random picker guy picking a 
     * random move out of valid moves. 
     * srand(time(NULL));
     * int random = rand()%array.size();
     * playerboard->doMove(array[random], color);
     * return array[random];
     * 
     */
	
	//cerr << array[0]->getX() << ", " << array[0]->getY() << endl;
    //return array[1];
	//return nullptr;
	
	
	
	
	// This calls Heuristic Player
	//return heuristicPlayer(opponentsMove, msLeft);
	
	
	
	
	
	
	
	
	
	
	// This calls the Minimax player
	
	
	
	// copy, make new_move, get the best move for black player, array of moves and corresponding scores
	Board *copy_board = playerboard->copy();
	Player *next_player = new Player(BLACK);
	
	// create two arrays, one for WHITE and one for BLACK AI's
	vector<Move*> white array, black_array;
	
	// keep track of total score
	int max_score;
	
	// base case if there are no valid moves for the AI
	if(copy_board->hasMoves(color) == false)
	{
		return nullptr;
	}
	
	//creating the array of valid moves
	else
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++) 
			{
				Move * move = new Move(i, j);         	
            	if (copy_board->checkMove(move, color))
            	{
            		white_array.push_back(move);
            	}
        	}
    	}
    	
    	// This is the code for our heuristic and beating simpleplayer
    	maxscore = playerboard->getMoveScore(array[0], color);
    	for (unsigned int i = 0; i < array.size(); i++)
    	{
    		if (playerboard->getMoveScore(array[i], color) > maxscore)
    		{
    			desiredmove = i;
    			maxscore = playerboard->getMoveScore(array[i], color);
    		}
    	}
    	playerboard->doMove(array[desiredmove], color);
    	return array[desiredmove];
	}
}
	
