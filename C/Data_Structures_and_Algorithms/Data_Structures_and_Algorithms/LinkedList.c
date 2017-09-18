//
//  LinkedList.c
//  Data_Structures_and_Algorithms
//
//  Created by Joshua Weldon on 9/13/17.
//  Copyright © 2017 Joshua Weldon. All rights reserved.
//

#include "LinkedList.h"

struct LinkedListNode {
    struct LinkedListNode * next;
    void                  * data;
};

struct LinkedList {
    LinkedListNode * head;
    bool          (* isEqual)(void *, void *);
};

LinkedListNode * lln_init(void * data){
    LinkedListNode * node = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    
    node->data = data;
    node->next = NULL;
    
    return node;
}

LinkedList * ll_init(bool (* isEqual) (void*, void*)){
    LinkedList * list = (LinkedList *) malloc(sizeof(LinkedList));
    
    list->head     = NULL;
    list->isEqual  = isEqual;
    
    return list;
}

void ll_destroy(LinkedList * list){
    
    LinkedListNode * current = list->head;
    LinkedListNode * save;
    while (current) {
        save = current;
        current = current->next;
        free(save->data);
        free(save);
    }
    
    free(list);
}

bool ll_add(LinkedList * list, void * data){
    
    LinkedListNode * endNode = lln_init(data);
    LinkedListNode * current = list->head;
    
    if(current == NULL){
        list->head = endNode;
        return true;
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = endNode;
    
    return true;
}

void ll_clear(LinkedList * list){
    
    void * data;
    
    while (!ll_isEmpty(list)) {
        data = ll_remove(list);
        free(data);
    }
    
    return;
}

void * ll_remove(LinkedList * list){
    
    if(list->head == NULL) return NULL;
    
    void * data = list->head->data;
    void * save = list->head;
    
    list->head = list->head->next;
    
    free(save);
    
    return data;
}

void ll_push(LinkedList * list, void * data){
    
    LinkedListNode * newNode = lln_init(data);
    
    newNode->next = list->head;
    list->head    = newNode;
    
    return;
}

void * ll_pop(LinkedList * list){
    
    if(list->head == NULL) return NULL;
    
    void * data = list->head->data;
    void * save = list->head;
    
    list->head = list->head->next;
    
    free(save);
    
    return data;
}

void * ll_peek(LinkedList * list){
    
    if(list->head == NULL) return NULL;
    
    return list->head->data;
}

void ll_addAt(LinkedList * list, int index, void * data){
    
    LinkedListNode * newNode = lln_init(data);
    LinkedListNode * current = list->head;

    int i;
    
    if(index == 0){
        newNode->next = list->head;
        list->head    = newNode;
        return;
    }
    
    for(i = 0; i < index - 1; i++){
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    return;
}

void * ll_removeAt(LinkedList * list, int index){
    
    LinkedListNode * current = list->head;
    void           * data;
    void           * save;
    
    int i;
    
    if(index == 0){
        data       = list->head->data;
        save       = list->head;
        list->head = list->head->next;
        free(save);
        return data;
    }
    
    for (i = 1; i < index; i++) {
        current = current->next;
    }
    
    data = current->next->data;
    save = current->next;
    
    current->next = current->next->next;
    
    free(save);
    
    return data;
}

int ll_indexOf(LinkedList * list, void * data){
    
    LinkedListNode * current = list->head;
    int i = 0;
    
    while(current != NULL){
        
        if(list->isEqual(data, current->data)) return i;
        
        current = current->next;
        i++;
    }
    
    return -1;
}

void * ll_get(LinkedList * list, int index){
    
    LinkedListNode * current = list->head;
    
    int i;
    
    for (i = 0; i < index; i++) {
        current = current->next;
    }
    
    return current->data;
}

int ll_size(LinkedList * list){
    
    LinkedListNode * current = list->head;
    int i = 0;
    
    while(current != NULL){
        i++;
        current = current->next;
    }
    
    return i;
}

int ll_isEmpty(LinkedList * list){
    
    return list->head == NULL;
}

char * ll_toString(LinkedList * list, char * (* data_toString)(void *)){
    
    LinkedListNode * current = list->head;
    char * string;
    char * pointer;
    char ** array;
    int length;
    int size;
    int i;
    
    if(current == NULL){
        string = (char *) malloc(sizeof("NULL"));
        strcpy(string, "NULL");
        return string;
    }
    
    size = ll_size(list);
    
    array = (char **) malloc(sizeof(char*) * size);
    
    array[0] = data_toString(current->data);
    current = current->next;
    length = (int) strlen(array[0]) + 1;
    
    for(i = 1; i < size; i++){
        array[i] = data_toString(current->data);
        length += (int) strlen(array[i]) + 4;
        
        current = current->next;
    }
    
    string = malloc(sizeof(char) * length);
    pointer = string;
    strcpy(pointer, array[0]);
    pointer += strlen(array[0]);
    free(array[0]);
    
    for(i = 1; i < size; i++){
        strcpy(pointer, " -> ");
        pointer += 4;
        strcpy(pointer, array[i]);
        pointer += strlen(array[i]);
        free(array[i]);
    }
    
    free(array);
    
    return string;
}
