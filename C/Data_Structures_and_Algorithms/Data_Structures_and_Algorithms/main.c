//
//  main.c
//  Data_Structures_and_Algorithms
//
//  Created by Joshua Weldon on 9/13/17.
//  Copyright © 2017 Joshua Weldon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Integer.h"


void ll_print(LinkedList * list){
    char * list_string;
    list_string = ll_toString(list, int_toString);
    printf("list: %s \n", list_string);
    free(list_string);
}

int main(int argc, const char * argv[]) {

    LinkedList * list;
    int * d1, * d2, * d3, * d4, * d5;
    int * temp;
    int i;
    
    d1 = (int *) malloc(sizeof(int));
    d2 = (int *) malloc(sizeof(int));
    d3 = (int *) malloc(sizeof(int));
    d4 = (int *) malloc(sizeof(int));
    d5 = (int *) malloc(sizeof(int));
    
    *d1 = 1;
    *d2 = 2;
    *d3 = 3;
    *d4 = 4;
    *d5 = 5;
    
    list = ll_init(int_isEqual);
    printf("initialize list \n");
    
    ll_print(list);
    
    ll_add(list, d1);
    printf("add 1 \n");
    
    ll_print(list);
    
    ll_add(list, d3);
    printf("add 3 \n");
    
    ll_print(list);
    
    ll_add(list, d5);
    printf("add 5 \n");
    
    ll_print(list);
    
    ll_add(list, d4);
    printf("add 4 \n");
    
    ll_print(list);
    
    temp = ll_remove(list);
    printf("removed head = %d \n", *temp);
    
    ll_print(list);
    
    temp = ll_peek(list);
    printf("peek = %d \n", *temp);
    
    ll_print(list);
    
    temp = ll_pop(list);
    printf("pop = %d \n", *temp);
    
    ll_print(list);
    
    temp = ll_get(list, 1);
    printf("get at index 1 = %d \n", *temp);
    
    ll_print(list);
    
    i = ll_size(list);
    printf("size = %d \n", i);
    
    ll_print(list);
    
    ll_push(list, d2);
    printf("push 2 \n");
    
    ll_print(list);
    
    ll_addAt(list, 1, d1);
    printf("add 1 at index 1 \n");
    
    ll_print(list);
    
    ll_removeAt(list, 2);
    printf("remove at index 2 \n");
    
    ll_print(list);
    
    i = ll_indexOf(list, d1);
    printf("index of 1 = %d \n", i);
    
    ll_print(list);
    
    ll_destroy(list);
    printf("distroyed list \n");
    
    free(d3);
    free(d5);
 
    return 0;
 
}
 
 
