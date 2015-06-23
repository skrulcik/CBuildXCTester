//
//  linkedlists.c
//  CTester
//
//  Created by Scott Krulcik on 6/22/15.
//  Copyright © 2015 Scott Krulcik. All rights reserved.
//

#include <stdlib.h>
#include "linkedlists.h"

LL *LL_create_primitive() {
    LL *newList = (LL *)malloc(sizeof(LL));
    newList->first = NULL;
    newList->last = NULL;
    newList->elemEqual = NULL;
    return newList;
}

LL *LL_create(bool (*isEqual)(void *, void *)) {
    LL *newList = (LL *)malloc(sizeof(LL));
    newList->first = NULL;
    newList->last = NULL;
    newList->elemEqual = isEqual;
    return newList;
}

void LL_push(LL *list, void *object) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = object;
    newNode->next = NULL;
    if (!list->first) {
        list->first = newNode;
        list->last = newNode;
    } else {
        newNode->next = list->first;
        list->first = newNode;
    }
}


bool LL_isEmpty(LL *list) {
    return list->first == NULL;
}

bool LL_contains(LL *list, void *elem) {
    node *test = list->first;
    while (test) {
        if (list->elemEqual(elem, test->data)) {
            return true;
        }
        test = test->next;
    }
    return false;
}

void *LL_pop(LL *list) {
    node *oldNode = list->first;
    list->first = list->first->next;
    if (!list->first) {
        list->last = NULL;
    }
    void *data = oldNode->data;
    free(oldNode);
    return data;
}

void LL_free(LL *list) {
    while(!LL_isEmpty(list)) {
        LL_pop(list);
    }
    free(list);
}




