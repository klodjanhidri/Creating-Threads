/*
    Klodjan Hidri
    AM2726
 */
#include "join_hashTable.h"
     

struct hash *hashTable = NULL;
int eleCount = 0;    

struct node{
    int key;
    Thread *th;
    struct node *next;
};

struct hash {
    struct node *head;
    int count;
};


void create_hashTable_Join(){
    int i=0;
    eleCount=10000;
    hashTable = (struct hash *) calloc(eleCount, sizeof(struct hash));
}
    
struct node * createNode(int key, Thread *th) {
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->key = key;
    newnode->th=th;
    newnode->next = NULL;
    return newnode;
}

     

void insertToHashTable_Join(int key, Thread *th){
    int hashIndex = key % eleCount;
    struct node *newnode = createNode(key, th);
    if (!hashTable[hashIndex].head) {
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }
    newnode->next = (hashTable[hashIndex].head);
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
}

void put_from_Join_to_readyqueue(int key) {
    int hashIndex = key % eleCount;
    struct node *temp, *myNode;
    myNode = hashTable[hashIndex].head;
    if (!myNode) {
        printf("Given data is not present in JOIN!!\n");
        return;
    }
    temp = myNode;
    while (myNode != NULL) {
        if (myNode->key == key) {
            if (myNode == hashTable[hashIndex].head)
                hashTable[hashIndex].head = myNode->next;
            else
                temp->next = myNode->next;
            hashTable[hashIndex].count--;
            enq(myNode->th);
            free(myNode);
            break;
        }
        temp = myNode;
        myNode = myNode->next;
    }
}

int searchInHashTable_Join(int key){
    int hashIndex = key % eleCount;
    struct node *myNode;
    myNode = hashTable[hashIndex].head;
    if (!myNode){
        return 0;
    }
    while (myNode != NULL) {
        if (myNode->key == key) {
            return 1;
        }
        myNode = myNode->next;
    }
    return 0;
}
