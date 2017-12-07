#include "player.h"

/**
 * @param human the human player to initialise
 **/
enum input_result get_human_player(struct player* human)
{   
    /*init's the player if there is a problem return failure*/
    printf("Please enter your name:\n");
    if(getString(human->name, NAMELEN) == RTM){

        return RTM;
    
    }else{

         human->counters = 0;
         human->type = HUMAN;

         return SUCCESS;
    }
    
    return FAILURE;
}

/**
 * @param computer the computer player to initialise
 **/
enum input_result get_computer_player(struct player * computer)
{
    
    strcpy(computer->name,"computer");
    computer->counters = 0;
    computer->type = COMPUTER;

    return SUCCESS;
}
/*assign a color randomly to players and returns struct player*/
struct player * player_color_selection(struct player* human, 
                struct player * computer)
{
    int color_selection;
    color_selection = random_number(2);
    
    if(color_selection == 0)
    {
        human->thiscolor = C_WHITE;
        computer->thiscolor = C_RED;
        
        return human;
    }
    else{
        
        human->thiscolor = C_RED;
        computer->thiscolor = C_WHITE;

        return computer;
    }
}
/*Controls the taking of turns, for human and computer. Computer player plays by
calling the random number generator*/
enum input_result take_turn(struct player * current,
        enum cell_contents board[][BOARDWIDTH]){

    int position, pos_Y = 5;
    BOOLEAN validateMove = FALSE; 
    
    char* prompt = 
    "\nPlease select a position to drop a token, or press Ctrl-D to exit\n";
    
    if(current->type == HUMAN){
        if(getInteger(&position, 2, prompt, 1, 7) == RTM){
            /*if the user selects enter or ctrl-D game will return to menu*/
            return RTM;
        }

        do{ 
            /*checks if column in full*/            
            if ((board[0][position-1] == C_WHITE)
                            ||(board[0][position-1] == C_RED)) {
                /*requests to re-enter if column full then resets posY*/ 
                printf("That coloumn is full please try again!");
                if(getInteger(&position, 2, prompt, 1, 7) == RTM){

                    return RTM;
                }
                pos_Y = 5; 
            }/*Drops the token and returns to calling function*/
            if(board[pos_Y][position-1] != C_WHITE)
                if (board[pos_Y][position-1] != C_RED){
                
                    board[pos_Y][position-1] = current->thiscolor;
                    validateMove = TRUE;
            }
           
            pos_Y--;
        }while(validateMove == FALSE);
        current->counters++;

        return SUCCESS;
    }

    if(current->type == COMPUTER)
    {   /*generates random number for computer player*/    
        int pos_X = random_number(7);
           
        do{/*pos_Y holds y vertice value if it gets to -1 reset and generate new
                number*/
            if(pos_Y == -1){
                pos_X = random_number(7);
                pos_Y = 5;
            }/*If empty spot found place token and return to calling function*/
            if(board[pos_Y][pos_X] != C_WHITE) 
                if (board[pos_Y][pos_X] != C_RED){
                  
                    board[pos_Y][pos_X] = current->thiscolor;
                    pos_Y = 5;
                    validateMove = TRUE;
            }
        pos_Y--;
        }while(validateMove == FALSE);
        current->counters++;
    }
    return FAILURE;
}
