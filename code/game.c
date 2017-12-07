#include "game.h"
/*Function swaps current and other player thorughout the game*/
static void swap_players(struct player ** current, struct player ** other)
{
    struct player *tempPlayer;
    /*Stores struct current player in a temp variable and then swaps*/
    tempPlayer = *current;
    *current = *other;
    *other = tempPlayer; 
}

struct player * play_game(struct player * human , 
        struct player* computer)
{   /*Create 2 variables under player struct to hold human and computer*/
    struct player *current; 
    struct player *other;
    /*int position;*/
    int winner = G_NO_WINNER;
    /* declaration that allocates the board for the game */
    enum cell_contents board[BOARDHEIGHT][BOARDWIDTH];
    /* char* prompt = "\nPlease select a position to drop a token\n";*/
    initialise_board(board);
    /*if user hits enter or ctrl-D returns to menu*/
    if(get_human_player(human)==RTM){
        printf("You have chosen to return to the menu!\n");
        return NULL;
    }

    get_computer_player(computer);
    display_board(board);
    /*Set color selection to be used to determine 1st player*/
    if(player_color_selection(human, computer) == human){
        current = human; 
        other = computer;
    }
    else {
        current = computer;
        other = human;
    }
    printf("%s goes first!\n", current->name);

    do{
        /*if the player selects enter or ctrl-D game will return to menu*/
        if(take_turn(current,board) == RTM){
            printf("You have chosen to return to menu!\n");
            break;
        }
        winner = test_for_winner(board);
        
       if((winner != G_NO_WINNER)&&
            (winner != G_DRAW)){

            display_board(board);
            printf("%s is the WINNER!!", current->name);
            return current;
        }
        
        swap_players(&current, &other);
        display_board(board);
        printf("It's %s's turn!\n", current->name );
    }while(winner == G_NO_WINNER);

    if(winner == G_DRAW){
        printf("The game was a draw, no winner recorded!");
        return G_DRAW; 
    }
 return NULL;
}
/*Function that bound checks and returns a winner*/
enum game_state test_for_winner(
        enum cell_contents board[][BOARDWIDTH])
{

int i,j,winner;
    /*check if there are any empty places remaining on the board, by calling
        checkdraw function*/
    for(i = 0; i < BOARDHEIGHT; i++) {
        for(j = 0; j < BOARDWIDTH; j++) {
           
            if(checkDraw(i,j,board) == G_DRAW){
                return G_DRAW;
            }
            /*Tests Horizontal moves and bounds checks*/
            if((j+3)<BOARDWIDTH){
                winner = isFourInRow(i,j,1,0,board);   
                if(winner != G_NO_WINNER){
                    return winner;
                }
            }
            /*Tests vertical moves and bounds checks*/
            if((i+3)<BOARDHEIGHT){
                winner = isFourInRow(i,j,0,1,board);
                if(winner != G_NO_WINNER){
                    return winner;
                }
            }
            /*Tests diagonal \ and bounds checks*/
            if(((i+3)<BOARDHEIGHT)&&((j+3)<BOARDWIDTH)){
                winner = isFourInRow(i,j,1,1,board);
                if(winner != G_NO_WINNER){
                    return winner;
                }
            }
            /*Test diagonal / and bounds checks*/
            if(((i-3)>-1)&&((j+3)<BOARDWIDTH)){
                winner = isFourInRow(i,j,1,-1,board);
                if(winner != G_NO_WINNER){
                    return winner;
                }
            }
        }
    }
    /*Test if there are free spaces on the board*/
    for(i = 0; i<BOARDHEIGHT; i++){
        for(j = 0; j<BOARDWIDTH; j++){
            if(board[i][j] == C_EMPTY){
                
                return G_NO_WINNER;
            }
        }
    }
    return G_DRAW;
}
/*check if all pieces have been used on the board, return a draw or no win*/
enum game_state checkDraw(int x, int j, enum cell_contents board[][BOARDWIDTH]){
    
int placesRemaining = 42;
    /*check if there are any empty spots left on the board*/
    if(board[x][j] != C_EMPTY){
            
        placesRemaining--; 
            
        if(placesRemaining == 0){
            return G_DRAW;
        }   
    }
    return G_NO_WINNER;
}
/*this function test for winner in all directions, uses nextX and nextY 
                                            to decide  which vertice to check*/ 
enum game_state isFourInRow(int x, int j,int nextX, int nextY, 
                                        enum cell_contents board[][BOARDWIDTH]){
/* set variables - set token to 1 as there is one already placed for checking*/
int i,tokens_in_row = 1;
    
    for (i = 1; i < 4; i++){ 
        /*test if there's the same token next to current token,keeps a counter*/
        if((board[x][j] == board[x + i * nextY][j + i * nextX])&&
                                                (board[x][j]!= C_EMPTY)){   
            tokens_in_row++;
        }else{/*resets the token counter so can be used again*/
            tokens_in_row = 0;
        }     
    }/*if there are 4 corresponding tokens returns winner*/  
    if (tokens_in_row == 4){       
        return board[x][j];
    }
    return G_NO_WINNER;
}