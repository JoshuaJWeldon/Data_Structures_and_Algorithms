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
 converts an integer to a string
 
 Returns:
 the integer as a string
 
 Parameters:
   
 - data: the integer to convert
 
 Warning:
 Allocates Memory.
 
 */

char * int_toString(void * data){
    
    int * i = (int *) data;
    
    int    length = log10(*i) + 1;
    char * string = (char *) malloc(length);
    
    sprintf(string, "%d", *i);
    
    return string;
}

/**
 Compares two integers
 
 Returns:
 the result of the comparison
 
 Parameters:
 
 - d1: the first integer
 - d2: the second integer
 
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

/**
 converts an integer to a string
 
 @Returns:
 the integer as a string
 
 Parameters:
 
 - data: the integer to convert
 
 Warning:
 Allocates Memory.
 
 */

- (void) testPrintEmptyList{
    
    char * string = ll_toString(list, int_toString);
    
    XCTAssert(strcmp("NULL", string) == 0);
    
    free(string);
}

- (void)testAddElement {
    
    int * d;
    int size;
    
    size = ll_size(list);
    XCTAssert(size == 0);
    
    d = (int *) malloc(sizeof(int));
    *d = 1101;
    
    ll_add(list, d);
    
    size = ll_size(list);
    XCTAssert(size == 1, @"%i", *d);
    
    d = (int *) ll_peek(list);
    XCTAssert(*d == 1101, @"%i", *d);
}

/**
 
 
 
 */

-(void)testAddMultipleElements {
    
    int * pointer;
    int value;
    int size = 0;
    
    while(size++ < 1000){
        
        pointer = (int *) malloc(sizeof(int));
        value = (int) pointer;
        *pointer = value;
        ll_add(list, pointer);
        
        XCTAssert(size == ll_size(list), @"size: %i, ll_size: %i", size, ll_size(list));
        
        pointer = (int *) ll_get(list, size - 1);
        XCTAssert(*pointer == value, @"pointer: %i, value: %d", *pointer, value);
        
    }
}



@end
