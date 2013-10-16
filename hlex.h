/*
 * hlex.h
 *
 *  Created on: 14 Oct 2013
 *      Author: lukasz
 */

#ifndef HLEX_H_
#define HLEX_H_

/* ----- Constant Integer Variables ----- */

#define NUMBER_OF_STATES  100
#define ASCII_LITERAL_MAX 256

#define INPUT_MAX         500
#define BUFFER_MAX        100
#define TXT_MAX           10

#define START_POSITION 	  0
#define START_CHARACTER   0

#define ERROR             -9999
#define NAN               -1


/* ----- Constant Strings ----- */

const char* IDENTIFICATOR = "identyfikator";
const char* OPERATOR      = "operator";
const char* NUMBER        = "liczba";



/* ----- Enumerations ----- */

enum
{
    START_STATE = 0,
    STATE_ONE,
    STATE_TWO,
    STATE_THREE,
    STATE_FOUR,
    STATE_FIVE
};


#endif /* HLEX_H_ */
