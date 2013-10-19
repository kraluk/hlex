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

char input[INPUT_MAX] = "<html param=\"val\"><body>test</body></html>";
char buffer[BUFFER_MAX];
char txt[TXT_MAX];

int position = START_POSITION;


/* ----- Function Prototypes ----- */

int getCharacter();
void addLexem(const char* type, char* value);



/* ----- MAIN ----- */

int main(int argc, char** argv) {

	int state = START_STATE;
	int newState = START_STATE;
	int character = START_CHARACTER;

	prepareTransitionArray();

	printf("Wejscie: %s (%d)\n", input, (int) strlen(input));

	while ((character = getCharacter()) != ERROR) {
		sprintf(txt, "%c", character);

		if (TRANSITION_ARRAY[state][character] != NAN) {
			if (state != TRANSITION_ARRAY[state][character]) {

			    if (state == STATE_TWO || state == STATE_ELEVEN)
					addLexem(TAG_NAME, buffer);

				if (state == STATE_THREE)
				    addLexem(PARAMETER_SPACE, buffer);

				if (state == STATE_FOUR)
				    addLexem(PARAMETER, buffer);

				if (state == STATE_SIX)
				    addLexem(PARAMETER_VALUE, buffer);

				if (state == STATE_EIGHT || state == STATE_TEN)
				    addLexem(TAG_ENDING, buffer);

				if (state == STATE_NINE)
				    addLexem(TEXT, buffer);

				state = TRANSITION_ARRAY[state][character];

				strcpy(buffer, txt);
			} else {
				strcat(buffer, txt);
			}

			if (state == STATE_ONE)
			    addLexem(TAG_START, buffer);

			if (state == STATE_FIVE)
			    addLexem(PARAMETER_EQUALS, buffer);

			if (state == STATE_SIX)
			    addLexem(PARAMETER_QUOTE, buffer);

			if (state == STATE_NINE)
			    addLexem(TAG_STOP, buffer);

			if (state == STATE_ERROR)
				printf("\n\nBlad przetwarzania - pozycja: %d, wejscie: %s\n",
						position, buffer);
		}
	}

	printf("\n\nKoniec...");
	//getchar();
	return 0;
}



/* ----- Functions ----- */

int getCharacter() {

	if (position >= (int) strlen(input)) {
		return ERROR;
	}

	return input[position++];
}

void addLexem(const char* type, char* value) {

	printf("\nWykryto leksem %-20s: %15s", type, value);
}
