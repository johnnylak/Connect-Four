#include "board.h"
#include "player.h"

/*Initialises the gameboard*/
void initialise_board(enum cell_contents board[][BOARDWIDTH])
{
	int i,j;
	for(i = 0; i < BOARDHEIGHT; i++){
		for(j = 0; j < BOARDWIDTH; j++){
			board[i][j] = C_EMPTY;
		}
	}
}

/*Displays the game board - used throughout the game!*/
void display_board(enum cell_contents board[][BOARDWIDTH])
{
	int i,j;

  printf("| 1  | 2  | 3  | 4  | 5  | 6  | 7  |\n");

  for(i = 0; i < BOARDHEIGHT; i++){
    printf("------------------------------------\n");
    printf("|");
    
    for(j = 0; j < BOARDWIDTH; j++){
    
     switch(board[i][j])
     {
      case C_EMPTY:
      printf(" ");
      break;

      case C_RED:
        printf("%s", RED_TOKEN);
      break;

      case C_WHITE:
        printf("%s", WHITE_TOKEN);
      break;
      
    }
      printf("   |");    
    }
    printf("\n");
  }
  printf("------------------------------------\n");
}