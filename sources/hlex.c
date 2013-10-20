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

char input[INPUT_MAX] = "<html param=\"val\">\n\t<body param2=\"val2\" param3=\"val3\">test</body>\n\ttee\n\t<test/>\n\t<test2 param4=\"val4\"/>\n</html>";
//char input[INPUT_MAX] = "<99></99>";
char buffer[BUFFER_MAX];
char txt[TXT_MAX];

int position = START_POSITION;


/* ----- Function Prototypes ----- */

int getCharacter();
void addLexem(const char* type, char* value);



/* ----- MAIN ----- */

int main(int argc, char** argv) {

	int state = START_STATE;
	int oldState = START_STATE;
	int character = START_CHARACTER;

	prepareTransitionArray();

	printf("Wejscie: \n%s \n(%d)\n", input, (int) strlen(input));

	while ((character = getCharacter()) != ERROR) {
		sprintf(txt, "%c", character);

		if (TRANSITION_ARRAY[state][character] != NAN) {
			if (state != TRANSITION_ARRAY[state][character]) {

                if (((state == STATE_TWO) && (oldState == STATE_TWO))
                        || ((state == STATE_TEN) && (oldState == STATE_TEN)))
                    addLexem(TAG_NAME, buffer);

				if (state == STATE_FOUR)
				    addLexem(PARAMETER, buffer);

				if (state == STATE_SIX)
				    addLexem(PARAMETER_VALUE, buffer);

                if ((state == STATE_EIGHT) && (oldState == STATE_EIGHT))
                    addLexem(TEXT, buffer);

				oldState = state;
				state = TRANSITION_ARRAY[state][character];

				strcpy(buffer, txt);
			} else {

			    oldState = state;

				strcat(buffer, txt);
			}

			if (state == STATE_ONE)
			    addLexem(TAG_START, buffer);

			//if (state == STATE_THREE)
			//    addLexem(PARAMETER_SPACE, buffer);

			if (state == STATE_FIVE)
			    addLexem(PARAMETER_EQUALS, buffer);

			if (((state == STATE_SIX) && (oldState != STATE_SIX))
			        || ((state == STATE_TWO) && (oldState == STATE_SIX))) {
			    addLexem(PARAMETER_QUOTE, buffer);
			    strcpy(buffer, EMPTY_STRING);
			}

			if ((state == STATE_SEVEN) || (state == STATE_TEN)) {
			    addLexem(TAG_ENDING, buffer);
			    strcpy(buffer, EMPTY_STRING);
			}

			if ((state == STATE_TEN) && (oldState != STATE_TEN)) {
			    addLexem(TAG_STOP, buffer);
			    //strcpy(buffer, EMPTY_STRING);
			}

			if (state == STATE_ERROR) {
				printf("\n\nBlad przetwarzania - pozycja: %d, wejscie: %s\n",
						position, buffer);
				exit(-1);
			}

			//printf("\n__DEBUG [states]: (%d)(%d)\n", oldState, state);
			//printf("\n__DEBUG [buffers]: (%s)(%s)\n", buffer, txt);
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
