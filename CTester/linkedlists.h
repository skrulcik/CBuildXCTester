//
//  linkedlists.h
//  CTester
//
//  Created by Scott Krulcik on 6/22/15.
//  Copyright © 2015 Scott Krulcik. All rights reserved.
//

#ifndef linkedlists_c
#define linkedlists_c

#include <stdio.h>
#include <stdbool.h>

typedef struct _listNode {
    void *data;
    struct _listNode *next;
} node;

typedef struct {
    node *first;
    node *last;
    bool (*elemEqual)(void *a, void *b);
} LL;

LL *LL_create_primitive();
LL *LL_create(bool (*elemEqual)(void *, void *));

bool LL_isEmpty(LL *list);
bool LL_contains(LL *list, void *elem);
void LL_push(LL *list, void *object);
void *LL_pop(LL *list);

#endif /* linkedlists_c */
