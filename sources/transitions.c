/*
 * transitions.c
 *
 *  Created on: 16 Oct 2013
 *      Author: lukasz
 */

#include "hlex.h"
#include "enums.h"
#include "transitions.h"


/* ----- Global variables ----- */

int TRANSITION_ARRAY[NUMBER_OF_STATES][ASCII_LITERAL_MAX];	// extern!


/* ----- Functions ----- */

void prepareTransitionArray() {

	int state   = NAN;
	int charact = NAN;


	/* --- "Clearing" the array --- */

	for (state = 0; state < NUMBER_OF_STATES; state++) {
		for (charact = 0; charact < ASCII_LITERAL_MAX; charact++) {
			TRANSITION_ARRAY[state][charact] = NAN;
		}
	}


	/* --- S_0 --- */

	TRANSITION_ARRAY[0]['<'] = 1;


	TRANSITION_ARRAY[0]['>'] = STATE_ERROR;
	TRANSITION_ARRAY[0]['"'] = STATE_ERROR;
	TRANSITION_ARRAY[0]['/'] = STATE_ERROR;
	TRANSITION_ARRAY[0]['='] = STATE_ERROR;

	setSmallCharactersAsError(0);
	setGreatCharactersAsError(0);
	setNumbersAsError(0);


	/* --- S_1 --- */

	TRANSITION_ARRAY[1]['/'] = 10;

	setSmallCharactersAsState(1, 2);
	setGreatCharactersAsState(1, 2);


	TRANSITION_ARRAY[1]['<'] = STATE_ERROR;
	TRANSITION_ARRAY[1]['>'] = STATE_ERROR;
    TRANSITION_ARRAY[1]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[1]['='] = STATE_ERROR;

    setNumbersAsError(1);


	/* --- S_2 --- */

	TRANSITION_ARRAY[2]['>'] = 9;
	TRANSITION_ARRAY[2]['/'] = 8;
	TRANSITION_ARRAY[2][' '] = 3;

    setSmallCharactersAsState(2, 2);
    setGreatCharactersAsState(2, 2);
    setNumbersAsState(2, 2);


    TRANSITION_ARRAY[2]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[2]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[2]['='] = STATE_ERROR;


	/* --- S_3 --- */

    setSmallCharactersAsState(3, 4);
    setGreatCharactersAsState(3, 4);


	TRANSITION_ARRAY[3]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[3]['>'] = STATE_ERROR;
    TRANSITION_ARRAY[3]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[3]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[3]['='] = STATE_ERROR;

    setNumbersAsError(3);


	/* --- S_4 --- */

	TRANSITION_ARRAY[4]['='] = 5;

    setSmallCharactersAsState(4, 4);
    setGreatCharactersAsState(4, 4);
    setNumbersAsState(4, 4);


    TRANSITION_ARRAY[4]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[4]['>'] = STATE_ERROR;
    TRANSITION_ARRAY[4]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[4]['/'] = STATE_ERROR;


	/* --- S_5 --- */

	TRANSITION_ARRAY[5]['"'] = 6;


    TRANSITION_ARRAY[5]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[5]['>'] = STATE_ERROR;
    TRANSITION_ARRAY[5]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[5]['='] = STATE_ERROR;

    setSmallCharactersAsError(5);
    setGreatCharactersAsError(5);
    setNumbersAsError(5);


	/* --- S_6 --- */

	TRANSITION_ARRAY[6]['"'] = 7;

    setSmallCharactersAsState(6, 6);
    setGreatCharactersAsState(6, 6);
    setNumbersAsState(6, 6);


	TRANSITION_ARRAY[6]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[6]['>'] = STATE_ERROR;
    TRANSITION_ARRAY[6]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[6]['='] = STATE_ERROR;


	/* --- S_7 --- */

	TRANSITION_ARRAY[7][' '] = 3;
	TRANSITION_ARRAY[7]['/'] = 8;
	TRANSITION_ARRAY[7]['>'] = 9;


    TRANSITION_ARRAY[7]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[7]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[7]['='] = STATE_ERROR;

    setSmallCharactersAsError(7);
    setGreatCharactersAsError(7);
    setNumbersAsError(7);


	/* --- S_8 --- */

	TRANSITION_ARRAY[8]['>'] = 9;


    TRANSITION_ARRAY[8]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[8]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[8]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[8]['='] = STATE_ERROR;

    setSmallCharactersAsError(8);
    setGreatCharactersAsError(8);
    setNumbersAsError(8);


	/* --- S_9 --- */

	TRANSITION_ARRAY[9]['<'] = 1;

    setSmallCharactersAsState(9, 9);
    setGreatCharactersAsState(9, 9);
    setNumbersAsState(9, 9);


    TRANSITION_ARRAY[9]['>'] = STATE_ERROR;
    TRANSITION_ARRAY[9]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[9]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[9]['='] = STATE_ERROR;


	/* --- S_10 --- */

    setSmallCharactersAsState(10, 11);
    setGreatCharactersAsState(10, 11);


	TRANSITION_ARRAY[10]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[10]['>'] = STATE_ERROR;
    TRANSITION_ARRAY[10]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[10]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[10]['='] = STATE_ERROR;

    setNumbersAsError(10);


	/* --- S_11 --- */

	TRANSITION_ARRAY[11]['>'] = 9;

    setSmallCharactersAsState(11, 11);
    setGreatCharactersAsState(11, 11);
    setNumbersAsState(11, 11);


    TRANSITION_ARRAY[11]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[11]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[11]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[11]['='] = STATE_ERROR;
}


void setSmallCharactersAsError(int state) {

    setSmallCharactersAsState(state, STATE_ERROR);
}

void setGreatCharactersAsError(int state) {

    setGreatCharactersAsState(state, STATE_ERROR);
}

void setNumbersAsError(int state) {

    setNumbersAsState(state, STATE_ERROR);
}

void setSmallCharactersAsState(int inState, int outState) {

    char character = NULL_CHARACTER;

    for (character = 'a'; character <= 'z'; character++) {
        TRANSITION_ARRAY[inState][(int) character] = outState;
    }
}

void setGreatCharactersAsState(int inState, int outState) {

    char character = NULL_CHARACTER;

    for (character = 'A'; character <= 'Z'; character++) {
        TRANSITION_ARRAY[inState][(int) character] = outState;
    }
}

void setNumbersAsState(int inState, int outState) {

    char character = NULL_CHARACTER;

    for (character = '0'; character <= '9'; character++) {
        TRANSITION_ARRAY[inState][(int) character] = outState;
    }
}
