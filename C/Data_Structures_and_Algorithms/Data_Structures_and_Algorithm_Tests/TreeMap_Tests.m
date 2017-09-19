//
//  TreeMap_Tests.m
//  Data_Structures_and_Algorithms
//
//  Created by Joshua Weldon on 9/18/17.
//  Copyright © 2017 Joshua Weldon. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "TreeMap.h"

@interface TreeMap_Tests : XCTestCase

@end

TreeMap * tree;

@implementation TreeMap_Tests

- (void)setUp {
    [super setUp];
    
    tree = tm_init();
}

- (void)tearDown {
    
    tm_destroy(tree);
    
    [super tearDown];
}

- (void)testPut {
    
}

- (void)testRemove {
    
}

- (void)testSize {
    
}

- (void)testToString {
    
}

@end
