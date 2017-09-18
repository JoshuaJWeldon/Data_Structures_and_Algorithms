//
//  TreeMap.h
//  Data_Structures_and_Algorithms
//
//  Created by Joshua Weldon on 9/18/17.
//  Copyright © 2017 Joshua Weldon. All rights reserved.
//

#ifndef TreeMap_h
#define TreeMap_h

#include <stdio.h>

typedef struct TreeMap TreeMap;

typedef struct TreeNode TreeNode;

TreeNode * tn_init(void * data);

void tn_destroy(TreeNode * node);

TreeMap * tm_init();

void tm_put();




#endif /* BinarySearchTree_h */
