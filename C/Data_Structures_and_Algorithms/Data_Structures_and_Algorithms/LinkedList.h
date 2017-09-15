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
 
 @Warning
 Allocates memory.
 
 @Return
 a new LinkedListNode
 
 @Param data element to be stored
 
 */

LinkedListNode * lln_init(void * data);

/**
 
 Initializes a LinkedList
 
 @Warning
 Allocates memory.
 
 @Returns
 a new LinkedList
 
 @Param
 isEqual a function to compare two data elements
 
 */

LinkedList * ll_init(int (* isEqual) (void*, void*));

/**
 
 Frees the list, nodes, and data
 
 @Warning
 Deallocates memory.
 
 @Param
 list the linkedlist
 
 */

void ll_destroy(LinkedList * list);

/**
 
 Adds data to the end of the list.
 
 @Warning
 Allocates memory.
 
 @Remark
 Takes O(n) runtime
 
 @Param
 list the linkedlist
 
 @Param 
 data data to store
 
 */

void ll_add(LinkedList * list, void * data);

/**
 
 Removes the first item in the list.
 
 @Warning
 Deallocates memory.
 
 @Remark
 Takes O(1) runtime
 
 @Param
 list the linkedlist
 
 @Return
 The removed data
 
 */

void * ll_remove(LinkedList * list);

/**
 
 Adds data to the front of the list.
 
 @Warning
 Allocates memory.
 
 @Remark
 Takes O(1) runtime
 
 @Param
 list the linkedlist
 
 @Param
 data data to store
 
 */

void ll_push(LinkedList * list, void * data);

/**
 
 Removes the first item in the list.
 
 @Warning
 Deallocates memory.
 
 @Remark
 Takes O(1) runtime
 
 @Param
 list the linkedlist
 
 @Return
 The removed data
 
 */

void * ll_pop(LinkedList * list);

/**
 
 Returns the first item's data in the list.
 
 @Remark
 Takes O(1) runtime
 
 @Param
 list the linkedlist
 
 @Return
 Data of the first node
 
 */

void * ll_peek(LinkedList * list);

/**
 
 Adds data to a given index of the list.
 
 @Warning
 Allocates memory.
 
 @Remark
 Takes O(n) runtime
 
 @Param
 list the linkedlist
 
 @Param 
 index the index in which to add
 
 @Param
 data the data to store
 
 */

void ll_addAt(LinkedList * list, int index, void * data);

/**
 
 Removes data at a given index of the list.
 
 @Warning
 Deallocates memory.
 
 @Remark
 Takes O(n) runtime
 
 @Param
 list the linkedlist
 
 @Param
 index the index of the item to remove
 
 @Return
 the data removed
 
 */

void * ll_removeAt(LinkedList * list, int index);

/**
 
 Returns the first index of a given data.
 
 @Remark
 Takes O(n) runtime
 
 @Param
 list the linkedlist
 
 @Param
 data data to find
 
 @Return
 The first index of given data
 
 */

int ll_indexOf(LinkedList * list, void * data);

/**
 
 Returns data at a given index of the list.
 
 @Remark
 Takes O(n) runtime
 
 @Param
 list the linkedlist
 
 @Param
 index the index of the item to get
 
 @Return
 the data at given index
 
 */

void * ll_get(LinkedList * list, int index);

/**
 
 Returns the size of the list.

 @Remark
 Takes O(n) runtime
 
 @Param
 list the linkedlist
 
 @Return
 the size of the list
 
 */

int ll_size(LinkedList * list);

/**
 
 Returns the list as a string.
 
 @Warning
 Allocates Memory.
 
 @Param
 list the linkedlist
 
 @Param
 data_toString a function to convert a data element to a string
 
 @Return
 the linkedlist as a string.
 
 */

char * ll_toString(LinkedList * list, char * (* data_toString)(void *));

#endif /* LinkedList_h */
