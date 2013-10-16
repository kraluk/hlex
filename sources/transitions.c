/*
 * transitions.c
 *
 *  Created on: 16 Oct 2013
 *      Author: lukasz
 */

#include "hlex.h"
#include "transitions.h"


/* ----- Global variables ----- */

int TRANSITION_ARRAY[NUMBER_OF_STATES][ASCII_LITERAL_MAX];	// extern!


/* ----- Functions ----- */

void prepareTransitionArray() {

	int state   = NAN;
	int charact = NAN;

	char character = NULL_CHARACTER;


	/* --- "Clearing" the array --- */

	for (state = 0; state < NUMBER_OF_STATES; state++) {
		for (charact = 0; charact < ASCII_LITERAL_MAX; charact++) {
			TRANSITION_ARRAY[state][charact] = NAN;
		}
	}


	/* --- S_0 --- */

	TRANSITION_ARRAY[0]['<'] = 1;


	/* --- S_1 --- */

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[1][(int) character] = 2;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[1][(int) character] = 2;
	}

	TRANSITION_ARRAY[1]['/'] = 10;


	/* --- S_10 --- */

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[10][(int) character] = 11;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[10][(int) character] = 11;
	}


	/* --- S_11 --- */

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[11][(int) character] = 11;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[11][(int) character] = 11;
	}

	for (character = '0'; character <= '9'; character++) {
		TRANSITION_ARRAY[11][(int) character] = 11;
	}

	TRANSITION_ARRAY[11]['>'] = 9;


	/* --- S_9 --- */

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[9][(int) character] = 9;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[9][(int) character] = 9;
	}

	for (character = '0'; character <= '9'; character++) {
		TRANSITION_ARRAY[9][(int) character] = 9;
	}

	TRANSITION_ARRAY[9]['<'] = 9;


	/* --- S_2 --- */

	TRANSITION_ARRAY[2]['>'] = 9;
	TRANSITION_ARRAY[2]['/'] = 8;
	TRANSITION_ARRAY[2][' '] = 3;


	/* --- S_8 --- */

	TRANSITION_ARRAY[8]['>'] = 9;


	/* --- S_3 --- */

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[3][(int) character] = 4;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[3][(int) character] = 4;
	}


	/* --- S_4 --- */

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[4][(int) character] = 5;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[4][(int) character] = 5;
	}

	for (character = '0'; character <= '9'; character++) {
		TRANSITION_ARRAY[4][(int) character] = 5;
	}

	TRANSITION_ARRAY[4]['='] = 5;


	/* --- S_5 --- */

	TRANSITION_ARRAY[5]['"'] = 6;


	/* --- S_6 --- */

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[6][(int) character] = 7;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[6][(int) character] = 7;
	}

	for (character = '0'; character <= '9'; character++) {
		TRANSITION_ARRAY[6][(int) character] = 7;
	}


	/* --- S_7 --- */

	TRANSITION_ARRAY[7]['"'] = 2;
}
