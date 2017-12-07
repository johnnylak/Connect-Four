#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "helpers.h"
#include "scoreboard.h"
#include "player.h"
#include "game.h"
#include "bool.h"
/**
 * @file con4.h simply puts together all the other header files for 
 * inclusion in @ref con4.c
 **/

#define SWITCH 1

enum menu
{
  PLAY_GAME = 1, 
  DISPLAY_HIGH_SCORES = 2, 
  QUIT = 3
};

int printMenu(void);