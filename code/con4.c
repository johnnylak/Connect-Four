#include "con4.h"

int main(void)
{
    int option;
    char* menuPrompt = "\nPlease enter your choice\n";
    /* the scoreboard for keeping track of winners */
    scoreboard scores;
    /* the two players and a pointer to who won the last game */
    struct player human_player, computer_player, *winner;
     /*Seed RAND for use in random number generator*/
     srand(time(NULL));
    /* initialise the scoreboard */
     init_scoreboard(scores);

    /*display menu and get menu choice until the user chooses to quit */
    do
        {   /*Displays menu by calling printMenu function*/
            printMenu();
            /*Used to get menu option from user*/
            getInteger(&option, SWITCH + 1, menuPrompt, 1, 3);
           
            switch(option)
            {
                case PLAY_GAME: 
                    /*calls the play game function and passes players through*/
                    winner = play_game(&human_player, &computer_player);
                    /*Add winner to scoreboard if not a draw*/
                    if(winner != G_DRAW){
                        add_to_scoreboard(scores, winner);
                    }

                    break;

                case DISPLAY_HIGH_SCORES:
                    display_scores(scores);
                    break;

                case QUIT:
                    printf("Exiting......\n");
                    exit(EXIT_SUCCESS);
                
                default:
                    printf("Not Valid\n");
                    break;
            }
        }   while(option != 3);
    
    return EXIT_SUCCESS;
}

int printMenu(void)
{
    printf("\nWelcome to connect 4\n");
    printf("----------------------------\n");
    printf("1) Play Game\n");
    printf("2) Display High Scores\n");
    printf("3) Quit\n");

    return EXIT_SUCCESS;
}