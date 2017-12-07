#include "helpers.h"

/**
 * @file helpers.c contains various functions that help in the
 * implementation of the program. You should put functions you create
 * here unless they logically belong to another module (such as
 * player, board or game
 **/

void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch!=EOF && ch != '\n'); 
    /* gobble each character */
    /* reset the error status of the stream */
    clearerr(stdin);
}

/*Function written by Steven Burrows*/
int getInteger(int* integer, unsigned LENGTH_INT, char* prompt, int min, int max)
{
   #define LENGTH_INT 1
   int finished = FALSE;
   char tempString[LENGTH_INT + 2];
   int tempInteger = 0;
   char* endPtr;

   /* Continue to interact with the user until the input is valid. */
   do
   {
      /* Provide a custom prompt. */
      printf("%s", prompt);
      
      /* Accept input. "+2" is for the \n and \0 characters. 
         tests if the user has entered ctrl-D to return to menu*/
      if(fgets(tempString, LENGTH_INT + 2, stdin) == NULL){
         
         return RTM;
      }
      else{
         /*tests if the user has hit enter to return to menu*/
         if(tempString[0] == '\n'){
           
            return RTM;
         }
        
         /* A string that doesn't have a newline character is too long. */
         if (tempString[strlen(tempString) - 1] != '\n')
         {
            printf("Input was too long. Please try again\n");
            read_rest_of_line();
         }
         else
         {
            /* Overwrite the \n character with \0. */
            tempString[strlen(tempString) - 1] = '\0';

            /* Convert string to an integer. */
            tempInteger = (int) strtol(tempString, &endPtr, 10);

            /* Validate integer result. */
            if (strcmp(endPtr, "") != 0)
            {
               printf("Input was not numeric.\n");
            }
            else if (tempInteger < min || tempInteger > max)
            {
               printf("Input was not within range %d - %d.\n", min, max);
            }
            else
            {
               finished = TRUE;
            }
         }
      }
   } while (finished == FALSE);

   /* Make the result integer available to calling function. */
   *integer = tempInteger;
   
   return TRUE;
}

/*Function written by Steven Burrows*/
int getString(char* string, unsigned LENGTH)
{
   #define LENGTH 20
   int finished = FALSE;
   char tempString[LENGTH + 2];

   /* Continue to interact with the user until the input is valid. */
   do
   {        
      /* Accept input. "+2" is for the \n and \0 characters. 
         tests if the user has entered ctrl-D to return to menu*/
      if(fgets(tempString, LENGTH + 2, stdin) == NULL){

         return RTM;
      }
      else{/*tests if the user has hit enter to return to menu*/
      if(tempString[0] == '\n'){
           
           return RTM;
         }
      /* A string that doesn't have a newline character is too long. */
      if (tempString[strlen(tempString) - 1] != '\n')
      {
         printf("Input was too long. Please try again!\n");
         read_rest_of_line();
      }
      else
      {
         finished = TRUE;
      }
}
   } while (finished == FALSE);

   /* Overwrite the \n character with \0. */
   tempString[strlen(tempString) - 1] = '\0';
   
   /* Make the result string available to calling function. */
   strcpy(string, tempString);

   return TRUE;
}
/*gnerates a random number and returns number*/
int random_number(int n)
{
   /* Intializes random number generator */
   return rand() % n;
}