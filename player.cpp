#include "player.hpp"
#include <iostream>
#include <stdlib.h> 
#include <time.h>

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
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    color = side;	//side that the player is on
    playerboard = new Board();	//board that I deal with
    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */

	//making the opponents move first
	if (color == WHITE)
	{
		playerboard->doMove(opponentsMove, BLACK);
	}
	else
	{
		playerboard->doMove(opponentsMove, WHITE);
	}


	
	std::vector<Move*> array;

	//creating the array of valid moves
	if(playerboard->hasMoves(color))
	{
		for (int i = 0; i < 8; i++) {
        	for (int j = 0; j < 8; j++) {
            	Move * move = new Move(i, j);         	
            	if (playerboard->checkMove(move, color)){
            		//cerr << i << ", " << j << endl;
            		
            		playerboard->doMove(move, color);
            		return move;
            		//array.push_back(pointer);

            	}
        	}
    	}
	}
	
	return nullptr;
	
	/*
	srand(time(NULL));
	int random = rand()%array.size();
	playerboard.doMove(array[random], color);
	return array[random];
	*/


	//cerr << array[0]->getX() << ", " << array[0]->getY() << endl;
	//return array[1];
	//return nullptr;
	
	

    
}
