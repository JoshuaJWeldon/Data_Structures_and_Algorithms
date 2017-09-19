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
#include <stdbool.h>

/**
 
 A node that stores data for a LinkedList.
 
 */

typedef struct LinkedListNode LinkedListNode;

/**
 
 A singly linkedlist.
 
 */

typedef struct LinkedList LinkedList;

/**
 
 Initializes a LinkedListNode.
 
 @Warning
 Allocates memory.
 
 @Return
 A new LinkedListNode.
 
 @Param data 
 Element to be stored.
 
 */

LinkedListNode * lln_init(void * data);

/**
 
 Initializes a LinkedList.
 
 @Warning
 Allocates memory.
 
 @Param isEqual 
 A function to compare two data elements.
 
 @Return
 A new LinkedList.
 
 */

LinkedList * ll_init(bool (* isEqual) (void*, void*));

/**
 
 Frees the list, nodes, and data.
 
 @Warning
 Deallocates memory.
 
 @Param list 
 The linkedlist
 
 */

void ll_destroy(LinkedList * list);

/**
 
 Adds data to the end of the list.
 
 @Warning
 Allocates memory.
 
 @Remark
 Takes O(n) runtime.
 
 @Param list 
 The linkedlist.
 
 @Param data 
 Data to store.
 
 */

bool ll_add(LinkedList * list, void * data);

/**
 
 Removes all elements from the list.
 
 @Warning
 Deallocates Memory.
 
 @Remark
 Runtime O(n).
 
 @Param list
 The linkedList.
 
 */

void ll_clear(LinkedList * list);

/**
 
 Removes the first item in the list.
 
 @Warning
 Deallocates memory.
 
 @Remark
 Takes O(1) runtime.
 
 @Param list 
 The linkedlist.
 
 @Return
 The removed data.
 
 */

void * ll_remove(LinkedList * list);

/**
 
 Adds data to the front of the list.
 
 @Warning
 Allocates memory.
 
 @Remark
 Takes O(1) runtime.
 
 @Param list 
 The linkedlist.
 
 @Param data 
 Data to store.
 
 */

void ll_push(LinkedList * list, void * data);

/**
 
 Removes the first item in the list.
 
 @Warning
 Deallocates memory.
 
 @Remark
 Takes O(1) runtime
 
 @Param list 
 The linkedlist.
 
 @Return
 The removed data.
 
 */

void * ll_pop(LinkedList * list);

/**
 
 Returns the first item's data in the list.
 
 @Remark
 Takes O(1) runtime.
 
 @Param list 
 The linkedlist.
 
 @Return
 Data of the first node.
 
 */

void * ll_peek(LinkedList * list);

/**
 
 Adds data to a given index of the list.
 
 @Warning
 Allocates memory.
 
 @Remark
 Takes O(n) runtime.
 
 @Param list 
 The linkedlist.
 
 @Param index 
 The index in which to add.
 
 @Param data 
 The data to store.
 
 */

void ll_addAt(LinkedList * list, int index, void * data);

/**
 
 Removes data at a given index of the list.
 
 @Warning
 Deallocates memory.
 
 @Remark
 Takes O(n) runtime.
 
 @Param list 
 The linkedlist.
 
 @Param index 
 The index of the item to remove.
 
 @Return
 The data removed.
 
 */

void * ll_removeAt(LinkedList * list, int index);

/**
 
 Returns the first index of a given element.
 
 @Remark
 Takes O(n) runtime.
 
 @Param list 
 The linkedlist.
 
 @Param data 
 Data to find.
 
 @Return
 The first index of given data. [-1 if does not exist.]
 
 */

int ll_indexOf(LinkedList * list, void * data);

/**
 
 Returns data at a given index of the list.
 
 @Remark
 Takes O(n) runtime.
 
 @Param list 
 The linkedlist.
 
 @Param index 
 The index of the item to get.
 
 @Return
 The data at given index.
 
 */

void * ll_get(LinkedList * list, int index);

/**
 
 Returns the size of the list.

 @Remark
 Takes O(n) runtime.
 
 @Param list 
 The linkedlist.
 
 @Return
 The size of the list.
 
 */

int ll_size(LinkedList * list);

/**
 
 Returns true if this collection contains no elements. False otherwise;
 
 This implementation returns list->head == NULL.
 
 @Remark 
 Takes O(1) runtime.
 
 @Param list
 The linkedlist.
 
 @Return
 true if the list contains no elements. False otherwise;
 
 */

int ll_isEmpty(LinkedList * list);

/**
 
 Returns an ASCII representation of the LinkedList.
 
 @Warning
 Allocates Memory.
 
 @Param list 
 The linkedlist.
 
 @Param data_toString 
 A function to convert a data element to a string.
 
 @Return
 The linkedlist as a string.
 
 */

char * ll_toString(LinkedList * list, char * (* data_toString)(void *));

#endif /* LinkedList_h */
