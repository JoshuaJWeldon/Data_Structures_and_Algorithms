//
//  LinkedList_Tests.m
//  LinkedList_Tests
//
//  Created by Joshua Weldon on 9/14/17.
//  Copyright © 2017 Joshua Weldon. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "LinkedList.h"

@interface LinkedList_Tests : XCTestCase

@end

/**
 Converts an integer to a string.

 @Warning
 Allocates Memory.
 
 @Param data 
 The integer to convert.
 
 @Return
 The integer as a string.

 */

char * int_toString(void * data){
    
    int * i = (int *) data;
    
    int    length = log10(*i) + 1;
    char * string = (char *) malloc(length);
    
    sprintf(string, "%d", *i);
    
    return string;
}

/**
 Compares two integers.
 
 @Param d1 
 The first integer.
 
 @Param d2 
 The second integer.
 
 @Return
 The result of the comparison.
 
 
 */

int isEqual(void * d1, void * d2){
    
    int * data1 = (int *) d1;
    int * data2 = (int *) d2;
    
    return *data1 == *data2;
}

LinkedList * list;

@implementation LinkedList_Tests

- (void)setUp {
    [super setUp];
    
    list = ll_init(isEqual);
}

- (void)tearDown {
    [super tearDown];
    
    ll_destroy(list);
}

- (void) testAdd {
    
    int * d;
    int   size;
    
    size = ll_size(list);
    XCTAssert(size == 0);
    
    d = (int *) malloc(sizeof(int)); //Memory will be freed in tear down
    *d = 1101;
    
    ll_add(list, d);
    
    size = ll_size(list);
    XCTAssert(size == 1, @"%i", *d);
    
    d = (int *) ll_peek(list);
    XCTAssert(*d == 1101, @"%i", *d);
}

- (void) testAdd_Multiple {
    
    int * pointer;
    int   value;
    int   size = 0;
    
    while(size++ < 1000){
        
        pointer = (int *) malloc(sizeof(int)); //Memory will be freed in tear down
        value = (int) pointer;
        *pointer = value;
        ll_add(list, pointer);
        
        XCTAssert(size == ll_size(list), @"size: %i, ll_size: %i", size, ll_size(list));
        
        pointer = (int *) ll_get(list, size - 1);
        XCTAssert(*pointer == value, @"pointer: %i, value: %d", *pointer, value);
    }
}

- (void) testRemove{
    
    int * pointer = (int *) malloc(sizeof(int));
    int   value   = 2356;
    
    *pointer = value;
    
    ll_add(list, pointer);
    
    XCTAssert(ll_size(list) == 1, @"ll_size: %i", ll_size(list));
    
    pointer = ll_remove(list);
    XCTAssert(*pointer == value, @"pointer: %i, value: %i", *pointer, value);
    XCTAssert(ll_size(list) == 0, @"ll_size: %i", ll_size(list));
    
    free(pointer);
}

- (void) testRemove_Multiple{

    int * array[1000];
    int * pointer;
    int   i;
    
    for(i = 0; i < 1000; i++){
        array[i] = (int *) malloc(sizeof(int));
        *array[i] = i;
        ll_add(list, array[i]);
        
        XCTAssert(i+1 == ll_size(list), @"i+1: %i, ll_size: %i", i+1, ll_size(list));
    }
    
    for (i = 0; i < 1000; i++) {
        pointer = ll_remove(list);
        XCTAssert(i == *pointer, @"i: %i, pointer: %i", i, *pointer);
        XCTAssert(999-i == ll_size(list), @"999-i: %i, ll_size: %i", 999-i, ll_size(list));
        free(pointer);
    }
    
    XCTAssert(ll_size(list) == 0, @"ll_size: %i", ll_size(list));
}

- (void) testPush{

    int * pointer = (int *) malloc(sizeof(int)); //Memory will be freed in tear down
    int   value   = 83834;
    
    *pointer = value;
    ll_push(list, pointer);
    
    XCTAssert(ll_size(list) == 1, @"ll_size: %i", ll_size(list));
    
    pointer = ll_get(list, 0);
    XCTAssert(*pointer == value, @"ll_get at 0: %i, value: %i", *pointer, value);
}

- (void) testPush_Multiple{
    
    int * pointer;
    int   i;
    
    for(i = 0; i < 1000; i++){
        pointer  = (int *) malloc(sizeof(int)); //memory will be freed in tear down
        *pointer = i;
        
        ll_push(list, pointer);
        
        XCTAssert(i+1 == ll_size(list), @"i+1: %i, ll_size: %i", i+1, ll_size(list));
    }
    
    for (i = 0; i < 1000; i++) {
        
        pointer = ll_get(list, i);
        XCTAssert(999-i == *pointer, @"i: %i, pointer: %i", 999-i, *pointer);
    }
}

- (void) testPop{
    
    int * pointer = (int *) malloc(sizeof(int));
    int   value   = 19324;
    
    *pointer = value;
    
    ll_add(list, pointer);
    
    XCTAssert(ll_size(list) == 1, @"ll_size: %i", ll_size(list));
    
    pointer = ll_pop(list);
    XCTAssert(ll_size(list) == 0, @"ll_size: %i", ll_size(list));
    XCTAssert(*pointer == value, @"pointer: %i, value: %i", *pointer, value);
    
    free(pointer);
}

- (void) testPop_Mulitple{
    
    int * pointer;
    int   i;
    
    for(i = 0; i < 1000; i++){
        pointer = (int *) malloc(sizeof(int));
        *pointer = i;
        ll_add(list, pointer);
        
        XCTAssert(ll_size(list) == i+1, @"ll_size: %i, i+1: %i", ll_size(list), i+1);
    }
    
    for (i = 0; i < 1000; i++) {
        
        pointer = ll_pop(list);
        XCTAssert(*pointer == i, @"pointer: %i, i: %i", *pointer, i);
        XCTAssert(ll_size(list) == 999-i, @"ll_size: %i, 999-i: %i", ll_size(list), 999-i);
        free(pointer);
    }
    
    XCTAssert(ll_size(list) == 0, @"ll_size: %i", ll_size(list));
    
}

- (void) testPeek{
    
    int * pointer = (int *) malloc(sizeof(int)); //memory will be freed in tear down
    int   value   = 234234;
    
    *pointer = value;
    
    ll_add(list, pointer);
    
    pointer = ll_peek(list);
    
    XCTAssert(*pointer == value, @"pointer: %i, value: %i", *pointer, value);
    XCTAssert(ll_size(list) == 1, @"ll_size: %i", ll_size(list));
}

- (void) testPeek_Multiple{
    
    int * pointer, * first;
    int   i;
    
    for(i = 0 ; i < 1000; i++){
        
        pointer  = (int *) malloc(sizeof(int)); //memory freed in tear down
        *pointer = i;
        
        ll_push(list, pointer); //add to front
        first = pointer;
        pointer = ll_peek(list);
        XCTAssert(*pointer == *first, @"pointer: %i, i: %i", *pointer, i);
        XCTAssert(ll_size(list) == i+1, @"ll_size: %i, i+1: %i", ll_size(list), i+1);
        
        i++;
        
        pointer  = (int *) malloc(sizeof(int)); //memory freed in tear down
        *pointer = i;
        
        ll_add(list, pointer); //add to back
        pointer  = ll_peek(list);
        XCTAssert(*pointer == *first, @"pointer: %i, first: %i", *pointer, *first);
        XCTAssert(ll_size(list) == i+1, @"ll_size: %i, i+1: %i", ll_size(list), i+1);
    }
    
    XCTAssert(ll_size(list) == 1000, @"ll_size: %i", ll_size(list));
}

- (void) testAddAt_EmptyList{
    
    int * pointer = (int *) malloc(sizeof(int)); //Memory freed in tear down
    int   value = 1000;
    
    *pointer = value;
    
    ll_addAt(list, 0, pointer);
    
    XCTAssert(ll_size(list) == 1, @"ll_size: %i", ll_size(list));
    
    pointer = ll_peek(list);
    XCTAssert(*pointer == value, @"pointer: %i, value: %i", *pointer, value);
    
}

- (void) testAddAt_Front{
    
    int * pointer;
    int i;
    
    for(i = 1; i < 10; i++){
        pointer  = (int *) malloc(sizeof(int)); //memory freed in tear down
        *pointer = i;
        ll_add(list, pointer);
        XCTAssert(ll_size(list) == i, @"ll_size: %i, i: %i", ll_size(list), i);
    }
    
    pointer  = (int *) malloc(sizeof(int)); //memory freed in tear down
    *pointer = 0;
    ll_addAt(list, 0, pointer);
    
    pointer = ll_peek(list);
    XCTAssert(*pointer == 0, @"pointer: %i", *pointer);
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    
    for(i = 0; i < 10; i++){
        
        pointer = ll_get(list, i);
        XCTAssert(*pointer == i, @"pointer: %i, i: %i", *pointer, i);
    }
    
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
}

- (void) testAddAt_Back{
    
    int * pointer;
    int i;
    
    for(i = 0; i < 9; i++){
        pointer  = (int *) malloc(sizeof(int)); //memory freed in tear down
        *pointer = i;
        ll_add(list, pointer);
        XCTAssert(ll_size(list) == i+1, @"ll_size: %i, i+1: %i", ll_size(list), i+1);
    }
    
    pointer  = (int *) malloc(sizeof(int)); //memory freed in tear down
    *pointer = 9;
    ll_addAt(list, 9, pointer);
    
    pointer = ll_get(list, 9);
    XCTAssert(*pointer == 9, @"pointer: %i", *pointer);
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    
    for(i = 0; i < 10; i++){
        
        pointer = ll_get(list, i);
        XCTAssert(*pointer == i, @"pointer: %i, i: %i", *pointer, i);
    }
    
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
}

- (void) testAddAt_Middle{
    
    int * pointer;
    int i;
    
    for(i = 0; i < 10; i++){
        
        if(i == 5) continue;
        
        pointer  = (int *) malloc(sizeof(int)); //memory freed in tear down
        *pointer = i;
        
        ll_add(list, pointer);
    }
    
    XCTAssert(ll_size(list) == 9, @"ll_size: %i", ll_size(list));
    
    pointer  = (int *) malloc(sizeof(int)); //memory freed in tear down
    *pointer = 5;
    ll_addAt(list, 5, pointer);
    
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    
    pointer = ll_get(list, 5);
    XCTAssert(*pointer == 5, @"pointer: %i", *pointer);
    
    for (i = 0; i < 10; i++) {
        
        pointer = ll_get(list, i);
        XCTAssert(*pointer == i, @"pointer: %i, i: %i", *pointer, i);
    }
}

- (void) testRemoveAt_WithOneElement{
    
    int * pointer = (int *) malloc(sizeof(int));
    int   value   = 1234235;
    
    *pointer = value;
    
    ll_add(list, pointer);
    
    XCTAssert(ll_size(list) == 1, @"ll_size: %i", ll_size(list));
    
    pointer = ll_removeAt(list, 0);
    
    XCTAssert(*pointer == value, @"pointer: %i, value: %i", *pointer, value);
    XCTAssert(ll_size(list) == 0, @"ll_size: %i", ll_size(list));
    
    free(pointer);
}

- (void) testRemoveAt_first {
    
    int * pointer;
    int   i;
    
    for(i = 0 ; i < 10; i++){
        
        pointer  = (int *) malloc(sizeof(int)); //all memory but one will be freed at tear down
        *pointer = i;
        
        ll_add(list, pointer);
    }
    
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    
    pointer = ll_removeAt(list, 0);
    
    XCTAssert(*pointer == 0, @"pointer: %i", *pointer);
    XCTAssert(ll_size(list) == 9, @"ll_size: %i", ll_size(list));
    
    free(pointer);
    
    for(i = 0; i < 9; i++){
        
        pointer = ll_get(list, i);
        XCTAssert(*pointer == i+1, @"pointer: %i, i+1: %i", *pointer, i+1);
    }
}

- (void) testRemoveAt_middle {
    
    int * pointer;
    int   i;
    
    for(i = 0; i < 10; i++){
        pointer  = (int *) malloc(sizeof(int)); //All memory but one will be freed in tear down
        *pointer = i;
        
        ll_add(list, pointer);
    }
    
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    
    pointer = ll_removeAt(list, 5);
    
    XCTAssert(*pointer == 5, @"pointer: %i", *pointer);
    XCTAssert(ll_size(list) == 9, @"ll_size: %i", ll_size(list));
    
    
    free(pointer);
    
    for(i = 0; i < 5; i++){
        pointer = ll_get(list, i);
        XCTAssert(*pointer == i, @"pointer: %i, i: %i", *pointer, i);
    }
    for(i = 5; i < 9; i++){
        pointer = ll_get(list, i);
        XCTAssert(*pointer == i+1, @"pointer: %i, i-1: %i", *pointer, i+1);
    }
}

- (void) testRemoveAt_last{
    
    int * pointer;
    int   i;
    
    for(i = 0; i < 10; i++){
        pointer  = (int *) malloc(sizeof(int));
        *pointer = i;
        
        ll_add(list, pointer);
    }
    
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    
    pointer = ll_removeAt(list, 9);
    
    XCTAssert(*pointer == 9, @"pointer: %i", *pointer);
    XCTAssert(ll_size(list) == 9, @"ll_size: %i", ll_size(list));
    
    free(pointer);
    
    for (i = 0; i < 9; i++) {
        pointer = ll_get(list, i);
        XCTAssert(*pointer == i, @"pointer: %i, i: %i", *pointer, i);
    }
}

- (void) testIndexOf_EmptyList{
    
    int * pointer = malloc(sizeof(int));
    
    *pointer = 1234;
    
    XCTAssert(ll_size(list) == 0, @"ll_size: %i", ll_size(list));
    XCTAssert(ll_indexOf(list, pointer) == -1, @"ll_indexOf: %i", ll_indexOf(list, pointer));
    XCTAssert(ll_size(list) == 0, @"ll_size: %i", ll_size(list));
    
    free(pointer);
}

- (void) testIndexOf_WithOneElement{
    
    int * pointer = (int *) malloc(sizeof(int)); //memory is freed in tear down
    int   value   = 213423;
    
    *pointer = value;
    ll_add(list, pointer);
    
    XCTAssert(ll_size(list) == 1, @"ll_size: %i", ll_size(list));
    XCTAssert(ll_indexOf(list, &value) == 0, @"ll_indexOf: %i", ll_indexOf(list, &value));
    XCTAssert(ll_size(list) == 1, @"ll_size: %i", ll_size(list));
    XCTAssert(*(int *)ll_get(list, 0) == value, @"ll_get at 0: %i, value: %i", *(int *)ll_get(list, 0), value);
}

- (void) testIndexOf_First_Last_Middle_DoesNotExist{
    
    int * pointer;
    int   i;
    
    for (i = 0; i < 10; i++) {
        pointer  = (int *) malloc(sizeof(int)); //memory freed in tear down
        *pointer = i;
        
        ll_add(list, pointer);
    }
    
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    
    i = 0;
    XCTAssert(ll_indexOf(list, &i) == 0, @"ll_indexOf: %i", ll_indexOf(list, &i));
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    
    i = 5;
    XCTAssert(ll_indexOf(list, &i) == 5, @"ll_indexOf: %i", ll_indexOf(list, &i));
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    
    i = 9;
    XCTAssert(ll_indexOf(list, &i) == 9, @"ll_indexOf: %i", ll_indexOf(list, &i));
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    
    i = 10;
    XCTAssert(ll_indexOf(list, &i) == -1, @"ll_indexOf: %i", ll_indexOf(list, &i));
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
}

- (void)testGet_WithOneElement {
    
    int * pointer = (int *) malloc(sizeof(int)); //memory freed in tear down
    int   value   = 23423424;
    
    *pointer = value;
    ll_add(list, pointer);
    
    XCTAssert(ll_size(list) == 1, @"ll_size: %i", ll_size(list));
    XCTAssert(*(int *)ll_get(list, 0) == value, @"ll_get at 0: %i, value: %i", *(int *)ll_get(list, 0), value);
    XCTAssert(ll_size(list) == 1, @"ll_size: %i", ll_size(list));
}

- (void)testGet_First_Middle_Last {
    
    int * pointer;
    int   i;
    
    for(i = 0; i < 10; i++){
        
        pointer  = (int *) malloc(sizeof(int));
        *pointer = i;
        
        ll_add(list, pointer);
    }
    
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    XCTAssert(*(int *)ll_get(list, 0) == 0, @"ll_get: %i",*(int *) ll_get(list, 0));
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    XCTAssert(*(int *)ll_get(list, 5) == 5, @"ll_get: %i",*(int *) ll_get(list, 5));
    XCTAssert(ll_size(list) == 10, @"ll_size: %i", ll_size(list));
    XCTAssert(*(int *)ll_get(list, 9) == 9, @"ll_get: %i",*(int *) ll_get(list, 9));
}

- (void)testSize_EmptyList {
    
}

- (void)testSize_WithOneElement {
    
}

- (void)testSize_FullList {
    
}

- (void)testIsEmpty_EmptyList {
    
}

- (void)testIsEmpty_WithOneElement {
    
}

- (void)testIsEmpty_FullList {
    
}

- (void) testToString_EmptyList{
    
    char * string = ll_toString(list, int_toString);
    
    XCTAssert(strcmp("NULL", string) == 0);
    
    free(string);
}

- (void)testToString_WithOneElement {
    
}

- (void)testToString_WithFullList {
    
}

@end
