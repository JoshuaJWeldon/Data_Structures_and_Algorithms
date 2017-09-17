//
//  Integer.h
//  Data_Structures_and_Algorithms
//
//  Created by Joshua Weldon on 9/17/17.
//  Copyright © 2017 Joshua Weldon. All rights reserved.
//

#ifndef Integer_h
#define Integer_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 Converts an integer to a string.
 
 @Warning
 Allocates Memory.
 
 @Param data
 The integer to convert.
 
 @Return
 The integer as a string.
 
 */

char * int_toString(void * data);

/**
 Compares two integers.
 
 @Param d1
 The first integer.
 
 @Param d2
 The second integer.
 
 @Return
 The result of the comparison.
 
 
 */

int int_isEqual(void * d1, void * d2);

#endif /* Integer_h */
