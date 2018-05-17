#include "scoreboard.h"

/*Initialises the scoreboard*/
void init_scoreboard(scoreboard board)
{
	int i;

	for(i = 0; i < SCOREBOARDSIZE; i++){
		strcpy(board[i].name, "");

			board[i].counters = '\0';
	}
}
/*Display scores if scores exist*/
void display_scores(const scoreboard board)
{
	int i;

	printf("%-20s%s\n","| Player","| Scores");
	printf("_________________________________________\n");

	for(i = 0; i < SCOREBOARDSIZE; i++)
	{	/*if there an entry display the board*/
		if(board[i].counters != '\0'){
			printf("|%-19s|%-19d|\n",board[i].name, board[i].counters);
		}
	}
}
/*function that adds player to scoreboard*/
BOOLEAN add_to_scoreboard(scoreboard board, const score * sc)
{
    int minimum = 1;
    int i, position = 0;
 	/*calls the sort func. to sort the board*/
    sorted(board);
  	for (i = 0; i < SCOREBOARDSIZE; i++){
  		/*looks for the min number on the board and store it and its position*/
  		if (board[i].counters <= minimum){
       		minimum  = board[i].counters;
       		position = i;
    	}
    	/*if there is an empty plave on the board store the score and sort*/
    	if(board[i].counters == 0){
 			board[i] = *sc;
 			sorted(board);

		return EXIT_SUCCESS;
		}
  	}	/*if the board is full remove the min score and add new one and sort*/
  		if(sc->counters > minimum){
			board[position] = *sc;
			sorted(board);

		return EXIT_SUCCESS;
  		}

    return FALSE;
}

BOOLEAN sorted(scoreboard board){
	score tempScore;
    int j,k;
    	/*goes through the scoreboard and moves structs into postion based on
    		score*/
		for(j = 0; j < SCOREBOARDSIZE; j++){
    	for(k = 0; k < SCOREBOARDSIZE - 1; k++){
    		if(board[k].counters > board[k+1].counters){

    			tempScore = board[k+1];
    			board[k+1] = board[k];
    			board[k] = tempScore;
    		}
    	}
	}
	return FALSE;
}
