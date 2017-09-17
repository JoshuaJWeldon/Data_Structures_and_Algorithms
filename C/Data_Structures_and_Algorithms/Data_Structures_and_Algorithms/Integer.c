//
//  Integer.c
//  Data_Structures_and_Algorithms
//
//  Created by Joshua Weldon on 9/17/17.
//  Copyright © 2017 Joshua Weldon. All rights reserved.
//

#include "Integer.h"

char * int_toString(void * data){
    
    int * i = (int *) data;
    int    length = *i == 0? 1 : log10(*i) + 1;
    char * string = (char *) malloc(length);
    
    sprintf(string, "%d", *i);
    
    return string;
}

int int_isEqual(void * d1, void * d2){
    
    int * data1 = (int *) d1;
    int * data2 = (int *) d2;
    
    return *data1 == *data2;
}
