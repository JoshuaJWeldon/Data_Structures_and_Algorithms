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
#include <stdbool.h>
#include <limits.h>


/**
 
 Converts an integer to a string.
 
 @Warning
 Allocates Memory.
 
 @Param integer
 The integer to convert.
 
 @Return
 The integer as a string.
 
 */

char * int_toString(void * integer);

/**
 
 Indicates whether the first integer "is equal" to the second.
 
 @Param integer1
 The first integer.
 
 @Param integer2
 The second integer.
 
 @Return
 Result of the comparison.
 
 
 */

bool int_equals(void * integer1, void * integer2);

/**
 
 Compares the first integer with the second for order. 
 
 Returns a negative integer, zero, or a positive integer as the first integer is less than, equal to, or greater than the second.
 
 @Param integer1
 The first integer.
 
 @Param integer2
 The second integer.
 
 @Return
 Result of the comparison.
 
 */

int int_compareTo(void * integer1, void * integer2);

#endif /* Integer_h */
