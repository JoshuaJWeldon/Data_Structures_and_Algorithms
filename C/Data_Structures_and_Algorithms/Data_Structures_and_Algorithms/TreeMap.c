//
//  TreeMap.c
//  Data_Structures_and_Algorithms
//
//  Created by Joshua Weldon on 9/18/17.
//  Copyright © 2017 Joshua Weldon. All rights reserved.
//

#include "TreeMap.h"

struct TreeMapNode {
    void * key;
    void * value;
    TreeMapNode * right;
    TreeMapNode * left;
    TreeMapNode * parent;
};

struct TreeMap {
    TreeMapNode * root;
};

TreeMapNode * tn_init(void * value){
    return NULL;
}

void tn_destroy(TreeMapNode * node){
    return;
}

TreeMap * tm_init(){
    return NULL;
}

void tm_destroy(TreeMap * tree){
    return;
}

void * tm_remove(TreeMap * tree, void * key){
    return NULL;
}

void * tm_put(TreeMap * tree, void * key, void * value){
    return NULL;
}

int tm_size(TreeMap * tree){
    return 0;
}

char * tm_toString(TreeMap * tree){
    return NULL;
}
