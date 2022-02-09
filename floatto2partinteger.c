/*
 * floatto2partinteger.c
 *
 *  Created on: Feb 4, 2022
 *      Author: Gustavo Wegher
 *
 * Description:  Function used to convert a float number into two integers,
 * consisting in the Integer part of the float and the Fraction part (decimal part).
 * The main application is to print decimal numbers as char type, for example, in a LCD display.
 *
 * Function can be called in main function:
 *
 * int32_t IntegerPart, FractionPart;
 * static char pcInput;
 *
 * FloatTo2PartInteger(floatNumber, &IntegerPart, &FractionPart);
 * usprintf(pcInput, "%2d.1d", IntegerPart, FractionPart);
 *
 */

#include <stdint.h>        // Integer definition
#include <stdbool.h>       // Bool definition


void FloatTo2PartInteger(float FloatToConvert, int32_t* IntegerPart, int32_t* FractionPart){

    *IntegerPart = (int32_t) FloatToConvert;                   // Convert IntegerPart from float number
    *FractionPart = (int32_t) (FloatToConvert * 10.0f);        // Convert FractionPart from float number
    *FractionPart = *FractionPart - (*IntegerPart)*10;         // Remove IntegerPart from FractionPart

    if (*FractionPart < 0) {                                             // If FractionPart is negative
        *FractionPart *= -1;                                             // Multiply itself per -1 to obtain positive part
    }

}


