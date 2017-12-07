#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bool.h"
#include <time.h>


/**
 * @file helpers.h contains the datastructures used for various helper 
 * functioons and their function prototypes
 **/
#ifndef HELPERS_H
#define HELPERS_H
/**
 * the possible values that can be returned from custom input handling 
 * functions
 **/
enum input_result
{
    /**
     * the input was valid
     **/
    SUCCESS,
    /**
     * the input was not valld
     **/
    FAILURE,
    /**
     * the user requested to return to the menu either by pressing enter on
     * an empty line or pressing ctrl-d on an empty line
     **/
    RTM=-1
};

/**
 * call this function whenever you detect buffer overflow but only call this
 * function when this has happened.
 **/
void read_rest_of_line(void);

int getInteger(int* integer, unsigned LENGTH_INT, char* prompt, int min, int max);

int getString(char* string, unsigned LENGTH);

int random_number(int n);

#endif
