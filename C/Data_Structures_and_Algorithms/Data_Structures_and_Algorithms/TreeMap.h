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

/**
 
 Balanced Binary Search Tree using a Red-Black tree implementation.
 
 */

typedef struct TreeMap TreeMap;

/**
 
 A node used to store a value in a TreeMap.
 
 */

typedef struct TreeNode TreeMapNode;

/**
 
 Initalizes a TreeNode.
 
 @Warning
 Allocates Memory.
 
 @Param value
 The value to be stored.
 
 @Return
 The new TreeNode.
 
 */

TreeMapNode * tn_init(void * value);

/**
 
 Frees the memory of the node and the value stored.
 
 @Warning
 Deallocates Memory.
 
 @Param node
 The TreeNode.
 
 */

void tn_destroy(TreeMapNode * node);

/**
 
 Initalizes a TreeNode.
 
 @Warning
 Allocates Memory.
 
 @Return
 The new TreeMap.
 
 */

TreeMap * tm_init();

/**
 
 Frees the memory of the map, nodes and the values stored.
 
 @Warning
 Deallocates Memory.
 
 @Param tree
 The TreeMap.
 
 */

void tm_destroy(TreeMap * tree);

/**
 
 Removes a value in the tree associated with a given key.
 
 @Warning
 Deallocates Memory.
 
 @Param key
 The key to the value.
 
 @Returns
 The value associated with the given key.
 
 */

void * tm_remove(TreeMap * tree, void * key);

/**
 
 Inserts the given value into the true using the given key.
 
 @Warning
 Allocates Memory.
 
 @Param key
 The key for the value.
 
 @Param value
 The value to insert.
 
 @Return
 The previous value associated with the given key, or null if there was no pervious mapping.
 
 */

void * tm_put(TreeMap * tree, void * key, void * value);

/**
 
 Returns the number of key-value mappings in the tree.
 
 @Returns
 The number of mappings in the tree.
 
 */

int tm_size(TreeMap * tree);

/**
 
 Returns an ASCII representation of the tree.
 
 @Warning
 Allocates Memory.
 
 @Param tree
 The TreeMap.
 
 @Return
 The tree as a string.
 
 */


char * tm_toString(TreeMap * tree);


#endif /* BinarySearchTree_h */
