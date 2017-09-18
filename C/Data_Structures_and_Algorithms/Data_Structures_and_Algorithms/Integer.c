//
//  Integer.c
//  Data_Structures_and_Algorithms
//
//  Created by Joshua Weldon on 9/17/17.
//  Copyright © 2017 Joshua Weldon. All rights reserved.
//

#include "Integer.h"

char * int_toString(void * integer){
    
    int    i = *(int *) integer;
    int    length;
    char * string;
    
    //get length from log10
    if(i == INT_MIN){
        length = log10((i+1) * -1) + 1;
    }
    else if(i == 0){
        length = 1;
    }
    else if(i < 0){
        length = log10(i * -1) + 1;
    }
    else{ //positive
        length = log10(i) + 1;
    }
    
    string = (char *) malloc(length * sizeof(char));
    
    sprintf(string, "%d", i);
    
    return string;
}

bool int_equals(void * integer1, void * integer2){
    
    int * i1 = (int *) integer1;
    int * i2 = (int *) integer2;
    
    return *i1 == *i2;
}

int int_compareTo(void * integer1, void * integer2){
    
    int i1 = *(int *) integer1;
    int i2 = *(int *) integer2;
    
    //for very large integers
    int delta1 = (i1 < 0)? -1: 1;
    int delta2 = (i2 < 0)? -1: 1;
    if(delta1 != delta2) return delta1 - delta2;
    
    return i1 - i2;
}
