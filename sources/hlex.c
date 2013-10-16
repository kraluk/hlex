/*
 * hlex.c
 *
 *  Created on: 14 Oct 2013
 *      Author: lukasz
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hlex.h"
#include "constans.h"
#include "enums.h"


/* ----- Global Variables ----- */

int TRANSITION_ARRAY[NUMBER_OF_STATES][ASCII_LITERAL_MAX];

char input[INPUT_MAX] = "<html><body></body></html>";
char buffer[BUFFER_MAX];
char txt[TXT_MAX];

int position = START_POSITION;


/* ----- Function Prototypes ----- */

int getCharacter();

void addLexem(const char* type, char* value);
void prepareTransitionArray();



/* ----- MAIN ----- */

int main(int argc, char** argv) {

	int state = START_STATE;
	int character = START_CHARACTER;

	prepareTransitionArray();

	printf("Wejscie: %s\n", input);

	while ((character = getCharacter()) != ERROR) {
		sprintf(txt, "%c", character);

		if (TRANSITION_ARRAY[state][character] != NAN) {
			if (state != TRANSITION_ARRAY[state][character]) {
				if (state == STATE_ONE)
					addLexem(IDENTIFICATOR, buffer);

				if (state == STATE_TWO)
					addLexem(OPERATOR, buffer);

				if (state == STATE_THREE)
					addLexem(NUMBER, buffer);

				state = TRANSITION_ARRAY[state][character];

				strcpy(buffer, txt);
			} else {
				strcat(buffer, txt);
			}

			if (state == STATE_FOUR)
				printf("\n\nZakonczono przetwarzanie frazy - znak: %s\n",
						buffer);

			if (state == STATE_FIVE)
				printf("\n\nBlad przetwarzania - pozycja: %d, wejscie: %s\n",
						position, buffer);
		}
	}

	printf("\n");
	//getchar();
	return 0;
}



/* ----- Functions ----- */

void prepareTransitionArray() {

	int state;
	int charact;

	for (state = 0; state < NUMBER_OF_STATES; state++) {
		for (charact = 0; charact < ASCII_LITERAL_MAX; charact++) {
			TRANSITION_ARRAY[state][charact] = NAN;
		}
	}

	char character = '\0';


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

int getCharacter() {

	if (position > (int) strlen(input)) {
		return ERROR;
	}

	return input[position++];
}

void addLexem(const char* type, char* value) {

	printf("\nWykryto leksem %-20s: %15s", type, value);
}
