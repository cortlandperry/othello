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
	if (playerboard->hasMoves(color) == false)
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
     */
	
	//cerr << array[0]->getX() << ", " << array[0]->getY() << endl;
    //return array[1];
	//return nullptr;
	
	
	
	
	
	// This is the call to the Heuristic Player
	// return heuristicPlayer(opponentsMove, msLeft);
	
	
	
	
	/*
	// This code calls the Minimax player	
	
	// The move to be returned at the end of the minmax algorithm
	Move * best_move;
	
	// the maximum of the worst case scenarios and the score using the heuristic of the difference in number of stones on the board.
	int minimax = 0, score = 0;
	
	// represents the color of the opponent
	Side opponent = (color == BLACK) ? WHITE : BLACK;
	
	
	// base case if there are no valid moves for our AI
	if (playerboard->hasMoves(color) == false)
	{
		return nullptr;
	}
	
	// otherwise calculate the best move for our AI
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) 
		{
			Move *first_move = new Move(i, j);         	
			if (playerboard->checkMove(first_move, color))
			{
				// clone the playerboard so as to make first_move on it
				Board *first_board = playerboard->copy();
				// make first_move on the copied board
				first_board->doMove(first_move, color);
				
				// initialize the minimum variable
				int minimum;
				
				// loop through to find the possible moves on the cloned board after making the first_move
				for (int k = 0; k < 8; k ++)
				{
					for (int s = 0; s < 8; s++)
					{
						Move *second_move = new Move(k, s);
						if (first_board->checkMove(second_move, opponent))
						{
							// clone first_board so as to make second_move on it
							Board *second_board = first_board->copy();
							// make second_move on the copied board
							second_board->doMove(second_move, opponent);
							// calculate the simple heuristic score of the opponent on the second_board
							score = second_board->getSimpleScore(opponent);
							// compute the worst possible scenario for our AI
							if (score < minimum)
							{
								minimum = score;
							}
						}
					}
				}
				
				// compute the maximum of the worst-case scenarios for our AI
				if (minimax < minimum)
				{
					minimax = minimum;			
					best_move = first_move;
				}
			}
		}
	}
	
	return best_move;
	*/
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	// This code calls attempts to beat BetterPlayer going 4 levels deep 	
	
	// The move to be returned at the end of the minmax algorithm
	Move * best_move;
	
	// the maximum of the worst case scenarios and the score using the heuristic of the difference in number of stones on the board.
	int minimax = 0, score = 0;
	
	// represents the color of the opponent
	Side opponent = (color == BLACK) ? WHITE : BLACK;
	
	
	// base case if there are no valid moves for our AI
	if (playerboard->hasMoves(color) == false)
	{
		return nullptr;
	}
	
	// otherwise calculate the best move for our AI
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) 
		{
			Move *first_move = new Move(i, j);         	
			if (playerboard->checkMove(first_move, color))
			{
				// clone the playerboard so as to make first_move on it
				Board *first_board = playerboard->copy();
				// make first_move on the copied board
				first_board->doMove(first_move, color);
				
				// initialize the minimum variable
				int minimum;
				
				// loop through to find the possible moves on the cloned board after making the first_move
				for (int k = 0; k < 8; k ++)
				{
					for (int s = 0; s < 8; s++)
					{
						Move *second_move = new Move(k, s);
						if (first_board->checkMove(second_move, opponent))
						{
							// clone first_board so as to make second_move on it
							Board *second_board = first_board->copy();
							// make second_move on the copied board
							second_board->doMove(second_move, opponent);
							
						
							for (int l = 0; l < 8; l++)
							{
								for (int f = 0; f < 8; f++)
								{
									Move *third_move = new Move(l, f);
									if (second_board->checkMove(third_move, color))
									{
										Board *third_board = second_board->copy();
										third_board->doMove(third_move, color);
										
										for (int n = 0; n < 8;n++)
										{
											for (int p = 0; p < 8; p++)
											{
												Move *fourth_move = new Move(n, p);
												if (third_board->checkMove(fourth_move, opponent))
												{
													Board *fourth_board = third_board->copy();
													fourth_board->doMove(fourth_move, opponent);
							
													// calculate the simple heuristic score of the opponent on the fourth_board
													score = fourth_board->getSimpleScore(opponent);
							
													// compute the worst possible scenario for our AI
													if (score < minimum)
													{
														minimum = score;
													}
												}
											}
										}
									}
								}
							}
						}
						
						// compute the maximum of the worst-case scenarios for our AI
						if (minimax < minimum)
						{
							minimax = minimum;			
							best_move = first_move;
						}
					}
				}
			}
		}
	}
	cerr << best_move->getX() << endl;
	//playerboard->doMove(best_move, color);

	return best_move;	
}
	
