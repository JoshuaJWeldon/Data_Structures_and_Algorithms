//
//  Integer_Tests.m
//  Data_Structures_and_Algorithms
//
//  Created by Joshua Weldon on 9/18/17.
//  Copyright © 2017 Joshua Weldon. All rights reserved.
//

#import <XCTest/XCTest.h>
#import <string.h>
#import <stdbool.h>
#import <limits.h>
#import "Integer.h"

@interface Integer_Tests : XCTestCase

@end

int * integer;

@implementation Integer_Tests

- (void)setUp {
    [super setUp];
    
    integer = (int *) malloc(sizeof(int));
}

- (void)tearDown {
    
    free(integer);
    
    [super tearDown];
}

- (void)testToString_Zero {
    
    char * string;
    int    i = 0;
    
    string = int_toString(&i);
    
    XCTAssert(strcmp(string, "0") == 0, @"string: %s", string);
    
    free(string);
    
}

- (void)testToString_Negative {
    char * string;
    int    i = -1;
    
    string = int_toString(&i);
    
    XCTAssert(strcmp(string, "-1") == 0, @"string: %s", string);
    
    free(string);
}

- (void)testToString_Positive {
    char * string;
    int    i = 1;
    
    string = int_toString(&i);
    
    XCTAssert(strcmp(string, "1") == 0, @"string: %s", string);
    
    free(string);
}

- (void)testToString_NegativeLarge {
    char * string;
    int    i1 = INT_MIN;
    int    i2 = INT_MIN + 1;
    
    string = int_toString(&i1);
    XCTAssert(strcmp(string, "-2147483648") == 0, @"string: %s", string);
    free(string);
    
    string = int_toString(&i2);
    XCTAssert(strcmp(string, "-2147483647") == 0, @"string: %s", string);
    free(string);
}

- (void)testToSting_PositiveLarge {
    char * string;
    int    i = INT_MAX;
    
    string = int_toString(&i);
    
    XCTAssert(strcmp(string, "2147483647") == 0, @"string: %s", string);
    
    free(string);
}

- (void)testEquals_NegativeNegative {
    
    int i1 = -1;
    int i2 = -2;
    
    XCTAssert(int_equals(&i1, &i1) == true, @"i1: %i", i1);
    XCTAssert(int_equals(&i2, &i2) == true, @"i2: %i", i2);
    XCTAssert(int_equals(&i1, &i2) == false, @"i1: %i, i2: %i", i1, i2);
    XCTAssert(int_equals(&i2, &i1) == false, @"i2: %i, i1: %i", i2, i1);
}

- (void)testEquals_NegativePositive {
    
    int i1 = 1;
    int i2 = -2;
    
    XCTAssert(int_equals(&i1, &i1) == true, @"i1: %i", i1);
    XCTAssert(int_equals(&i2, &i2) == true, @"i2: %i", i2);
    XCTAssert(int_equals(&i1, &i2) == false, @"i1: %i, i2: %i", i1, i2);
    XCTAssert(int_equals(&i2, &i1) == false, @"i2: %i, i1: %i", i2, i1);
    
}

- (void)testEquals_PositivePositive {
    
    int i1 = 1;
    int i2 = 2;
    
    XCTAssert(int_equals(&i1, &i1) == true, @"i1: %i", i1);
    XCTAssert(int_equals(&i2, &i2) == true, @"i2: %i", i2);
    XCTAssert(int_equals(&i1, &i2) == false, @"i1: %i, i2: %i", i1, i2);
    XCTAssert(int_equals(&i2, &i1) == false, @"i2: %i, i1: %i", i2, i1);
}

- (void)testCompareTo_NegativeNegative {
    
    int i1 = -1;
    int i2 = -2;
    
    XCTAssert(int_compareTo(&i1, &i1) == 0, @"i1: %i", i1);
    XCTAssert(int_compareTo(&i2, &i2) == 0, @"i2: %i", i2);
    XCTAssert(int_compareTo(&i1, &i2) > 0, @"i1: %i, i2: %i", i1, i2);
    XCTAssert(int_compareTo(&i2, &i1) < 0, @"i2: %i, i1: %i", i2, i1);
}

- (void)testCompareTo_NegativePositive {
    
    int i1 = 1;
    int i2 = -2;
    
    XCTAssert(int_compareTo(&i1, &i1) == 0, @"i1: %i", i1);
    XCTAssert(int_compareTo(&i2, &i2) == 0, @"i2: %i", i2);
    XCTAssert(int_compareTo(&i1, &i2) > 0, @"i1: %i, i2: %i", i1, i2);
    XCTAssert(int_compareTo(&i2, &i1) < 0, @"i2: %i, i1: %i", i2, i1);
    
}

- (void)testCompareTo_PositivePositive {
    
    int i1 = 2;
    int i2 = 1;
    
    XCTAssert(int_compareTo(&i1, &i1) == 0, @"i1: %i", i1);
    XCTAssert(int_compareTo(&i2, &i2) == 0, @"i2: %i", i2);
    XCTAssert(int_compareTo(&i1, &i2) > 0, @"i1: %i, i2: %i", i1, i2);
    XCTAssert(int_compareTo(&i2, &i1) < 0, @"i2: %i, i1: %i", i2, i1);
    
}

- (void)testCompareTo_LargeNumbers {
    
    int i1 = INT_MAX;
    int i2 = INT_MIN;
    
    XCTAssert(int_compareTo(&i1, &i1) == 0, @"i1: %i", i1);
    XCTAssert(int_compareTo(&i2, &i2) == 0, @"i2: %i", i2);
    XCTAssert(int_compareTo(&i1, &i2) > 0, @"i1: %i, i2: %i", i1, i2);
    XCTAssert(int_compareTo(&i2, &i1) < 0, @"i2: %i, i1: %i", i2, i1);
}


@end
