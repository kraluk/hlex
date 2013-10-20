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

	char character = NULL_CHARACTER;


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

	for (character = 'a'; character <= 'z'; character++) {
        TRANSITION_ARRAY[0][(int) character] = STATE_ERROR;
    }

    for (character = 'A'; character <= 'Z'; character++) {
        TRANSITION_ARRAY[0][(int) character] = STATE_ERROR;
    }

    for (character = '0'; character <= '9'; character++) {
        TRANSITION_ARRAY[0][(int) character] = STATE_ERROR;
    }


	/* --- S_1 --- */

	TRANSITION_ARRAY[1]['/'] = 10;

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[1][(int) character] = 2;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[1][(int) character] = 2;
	}


	TRANSITION_ARRAY[1]['<'] = STATE_ERROR;
	TRANSITION_ARRAY[1]['>'] = STATE_ERROR;
    TRANSITION_ARRAY[1]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[1]['='] = STATE_ERROR;

    for (character = '0'; character <= '9'; character++) {
        TRANSITION_ARRAY[1][(int) character] = STATE_ERROR;
    }


	/* --- S_2 --- */

	TRANSITION_ARRAY[2]['>'] = 9;
	TRANSITION_ARRAY[2]['/'] = 8;
	TRANSITION_ARRAY[2][' '] = 3;

	for (character = 'a'; character <= 'z'; character++) {
        TRANSITION_ARRAY[2][(int) character] = 2;
    }

    for (character = 'A'; character <= 'Z'; character++) {
        TRANSITION_ARRAY[2][(int) character] = 2;
    }

    for (character = '0'; character <= '9'; character++) {
        TRANSITION_ARRAY[2][(int) character] = 2;
    }


    TRANSITION_ARRAY[2]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[2]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[2]['='] = STATE_ERROR;


	/* --- S_3 --- */

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[3][(int) character] = 4;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[3][(int) character] = 4;
	}


	TRANSITION_ARRAY[3]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[3]['>'] = STATE_ERROR;
    TRANSITION_ARRAY[3]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[3]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[3]['='] = STATE_ERROR;

    for (character = '0'; character <= '9'; character++) {
        TRANSITION_ARRAY[3][(int) character] = STATE_ERROR;
    }


	/* --- S_4 --- */

	TRANSITION_ARRAY[4]['='] = 5;

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[4][(int) character] = 4;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[4][(int) character] = 4;
	}

	for (character = '0'; character <= '9'; character++) {
		TRANSITION_ARRAY[4][(int) character] = 4;
	}


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

    for (character = 'a'; character <= 'z'; character++) {
        TRANSITION_ARRAY[5][(int) character] = STATE_ERROR;
    }

    for (character = 'A'; character <= 'Z'; character++) {
        TRANSITION_ARRAY[5][(int) character] = STATE_ERROR;
    }

    for (character = '0'; character <= '9'; character++) {
        TRANSITION_ARRAY[5][(int) character] = STATE_ERROR;
    }


	/* --- S_6 --- */

	TRANSITION_ARRAY[6]['"'] = 7;

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[6][(int) character] = 6;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[6][(int) character] = 6;
	}

	for (character = '0'; character <= '9'; character++) {
		TRANSITION_ARRAY[6][(int) character] = 6;
	}


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

    for (character = 'a'; character <= 'z'; character++) {
        TRANSITION_ARRAY[7][(int) character] = STATE_ERROR;
    }

    for (character = 'A'; character <= 'Z'; character++) {
        TRANSITION_ARRAY[7][(int) character] = STATE_ERROR;
    }

    for (character = '0'; character <= '9'; character++) {
        TRANSITION_ARRAY[7][(int) character] = STATE_ERROR;
    }


	/* --- S_8 --- */

	TRANSITION_ARRAY[8]['>'] = 9;


    TRANSITION_ARRAY[8]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[8]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[8]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[8]['='] = STATE_ERROR;

    for (character = 'a'; character <= 'z'; character++) {
        TRANSITION_ARRAY[8][(int) character] = STATE_ERROR;
    }

    for (character = 'A'; character <= 'Z'; character++) {
        TRANSITION_ARRAY[8][(int) character] = STATE_ERROR;
    }

    for (character = '0'; character <= '9'; character++) {
        TRANSITION_ARRAY[8][(int) character] = STATE_ERROR;
    }


	/* --- S_9 --- */

	TRANSITION_ARRAY[9]['<'] = 1;

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[9][(int) character] = 9;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[9][(int) character] = 9;
	}

	for (character = '0'; character <= '9'; character++) {
		TRANSITION_ARRAY[9][(int) character] = 9;
	}


    TRANSITION_ARRAY[9]['>'] = STATE_ERROR;
    TRANSITION_ARRAY[9]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[9]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[9]['='] = STATE_ERROR;


	/* --- S_10 --- */

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[10][(int) character] = 11;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[10][(int) character] = 11;
	}


	TRANSITION_ARRAY[10]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[10]['>'] = STATE_ERROR;
    TRANSITION_ARRAY[10]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[10]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[10]['='] = STATE_ERROR;

    for (character = '0'; character <= '9'; character++) {
        TRANSITION_ARRAY[10][(int) character] = STATE_ERROR;
    }


	/* --- S_11 --- */

	TRANSITION_ARRAY[11]['>'] = 9;

	for (character = 'a'; character <= 'z'; character++) {
		TRANSITION_ARRAY[11][(int) character] = 11;
	}

	for (character = 'A'; character <= 'Z'; character++) {
		TRANSITION_ARRAY[11][(int) character] = 11;
	}

	for (character = '0'; character <= '9'; character++) {
		TRANSITION_ARRAY[11][(int) character] = 11;
	}


    TRANSITION_ARRAY[11]['<'] = STATE_ERROR;
    TRANSITION_ARRAY[11]['"'] = STATE_ERROR;
    TRANSITION_ARRAY[11]['/'] = STATE_ERROR;
    TRANSITION_ARRAY[11]['='] = STATE_ERROR;
}
