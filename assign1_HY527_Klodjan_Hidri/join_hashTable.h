/*
    Klodjan Hidri
    AM2726
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queus.h"


struct node * createNode(int key, Thread *th);
void insertToHashTable_Join(int key, Thread *th);
void  put_from_Join_to_readyqueue(int key);
int searchInHashTable_Join(int key);
void create_hashTable_Join();
