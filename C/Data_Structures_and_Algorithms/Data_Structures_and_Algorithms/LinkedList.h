//
//  LinkedList.h
//  Data_Structures_and_Algorithms
//
//  Created by Joshua Weldon on 9/13/17.
//  Copyright © 2017 Joshua Weldon. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct LinkedListNode LinkedListNode;
typedef struct LinkedList     LinkedList;

/**
 
 Initializes a LinkedListNode
 
 Returns:
 a new LinkedListNode
 
 Parameters:

 - data: data to be stored
 
 Warning:
 Allocates memory.
 
 */

LinkedListNode * lln_init(void * data);

/**
 
 Initializes a LinkedList
 
 Returns:
 a new LinkedList
 
 Parameters:
 
 - isEqual: a function to compare two data objects
 
 Warning:
 Allocates memory.
 
 */

LinkedList * ll_init(int (* isEqual) (void*, void*));

/**
 
 Frees the list, nodes, and data.
 
 Returns:
 void
 
 Parameters:
 
 - list: the linkedlist
 
 Warning:
 Deallocates memory.
 
 */

void ll_destroy(LinkedList * list);

/**
 
 Adds data to the end of the list.
 
 Returns:
 void
 
 Parameters:
 
 - list: the linkedlist
 
 - data: data to store
 
 Warning:
 Allocates memory.
 
 Remark:
 Takes O(n) runtime
 
 */

void ll_add(LinkedList * list, void * data);

/**
 
 Removes the first item in the list.
 
 Returns:
 The removed data
 
 Parameters:
 
 - list: the linkedlist
 
 Warning:
 Deallocates memory.
 
 Remark:
 Takes O(1) runtime
 
 */

void * ll_remove(LinkedList * list);

/**
 
 Adds data to the front of the list.
 
 Returns:
 void
 
 Parameters:
 
 - list: the linkedlist
 
 - data: data to store
 
 Warning:
 Allocates memory.
 
 Remark:
 Takes O(1) runtime
 
 */

void ll_push(LinkedList * list, void * data);

/**
 
 Removes the first item in the list.
 
 Returns:
 The removed data
 
 Parameters:
 
 - list: the linkedlist
 
 Warning:
 Deallocates memory.
 
 Remark:
 Takes O(1) runtime
 
 */

void * ll_pop(LinkedList * list);

/**
 
 Returns the first item's data in the list.
 
 Returns:
 Data of the first node
 
 Parameters:
 
 - list: the linkedlist
 
 Remark:
 Takes O(1) runtime
 
 */

void * ll_peek(LinkedList * list);

/**
 
 Adds data to a given index of the list.
 
 Returns:
 void
 
 Parameters:
 
 - list: the linkedlist
 
 - index: the index in which to add
 
 - data: the data to store
 
 Warning:
 Allocates memory.
 
 Remark:
 Takes O(n) runtime
 
 */

void ll_addAt(LinkedList * list, int index, void * data);

/**
 
 Removes data at a given index of the list.
 
 Returns:
 the data removed
 
 Parameters:
 
 - list: the linkedlist
 
 - index: the index of the item to remove
 
 Warning:
 Deallocates memory.
 
 Remark:
 Takes O(n) runtime
 
 */

void * ll_removeAt(LinkedList * list, int index);

/**
 
 Returns the first index of a given data.
 
 Returns:
 The first index of given data
 
 Parameters:
 
 - list: the linkedlist
 
 - data: data to find
 
 Remark:
 Takes O(n) runtime
 
 */

int ll_indexOf(LinkedList * list, void * data);

/**
 
 Returns data at a given index of the list.
 
 Returns:
 the data at given index
 
 Parameters:
 
 - list: the linkedlist
 
 - index: the index of the item to get
 
 Remark:
 Takes O(n) runtime
 
 */

void * ll_get(LinkedList * list, int index);

/**
 
 Returns the size of the list.
 
 Returns:
 the size of the list
 
 Parameters:
 
 - list: the linkedlist
 
 Remark:
 Takes O(n) runtime
 
 */

int ll_size(LinkedList * list);

/**
 
 Returns the list as a string.
 
 Returns:
 the list as a string.
 
 Parameters:
 
 - list: the linkedlist
 
 - data_toString: a function to convert a data element to a string
 
 Warning:
 Allocates Memory.
 
 */

char * ll_toString(LinkedList * list, char * (* data_toString)(void *));

#endif /* LinkedList_h */
