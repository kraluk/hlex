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

#include "transitions.h"


/* ----- Global Variables ----- */

int TRANSITION_ARRAY[NUMBER_OF_STATES][ASCII_LITERAL_MAX];

char input[INPUT_MAX] = "<html><body></body></html>";
char buffer[BUFFER_MAX];
char txt[TXT_MAX];

int position = START_POSITION;


/* ----- Function Prototypes ----- */

int getCharacter();

void addLexem(const char* type, char* value);



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

int getCharacter() {

	if (position > (int) strlen(input)) {
		return ERROR;
	}

	return input[position++];
}

void addLexem(const char* type, char* value) {

	printf("\nWykryto leksem %-20s: %15s", type, value);
}
