/*
 * transitions.h
 *
 *  Created on: 16 Oct 2013
 *      Author: lukasz
 */

#ifndef TRANSITIONS_H_
#define TRANSITIONS_H_


/* ----- Externs ----- */

extern int TRANSITION_ARRAY[NUMBER_OF_STATES][ASCII_LITERAL_MAX];


/* ----- Functions ----- */

void prepareTransitionArray();

void setSmallCharactersAsError(int state);
void setGreatCharactersAsError(int state);
void setNumbersAsError(int state);

void setSmallCharactersAsState(int inState, int outState);
void setGreatCharactersAsState(int inState, int outState);
void setNumbersAsState(int inState, int outState);


#endif /* TRANSITIONS_H_ */
