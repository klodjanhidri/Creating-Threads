/*
    Klodjan Hidri
    AM2726
 */

#include "queus.h"



/* Create an empty queue */

struct READYQUEAUE* create()
{
    front = rear = NULL;
    return rear;
}

/* Enqueing the queue */
void enq(void* data)
{

    if (rear == NULL)
    {
        rear = (struct READYQUEAUE *)malloc(sizeof(struct READYQUEAUE));
        rear->ptr = NULL;
        rear->info = (void*)data;
        front = rear;
    }
    else
    {
        temp=(struct READYQUEAUE *)malloc(1*sizeof(struct READYQUEAUE));
        rear->ptr = temp;
        temp->info = (void*)data;
        temp->ptr = NULL;
        rear = temp;
    }
}


void *deq()
{
    void *tmp;
    front1 = front;
    
    if (front1 == NULL)
    {
        printf("\n Error: Trying to dequeue elements from empty queue");
        return (int *)-1;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            tmp=front->info;
            free(front);
            front = front1;
        }
        else
        {
            tmp=front->info;
            free(front);
            front = NULL;
            rear = NULL;
        }
        return tmp;
}

/*  queue is empty or not */
int empty()
{
    int boolean=0;
     if ((front == NULL) && (rear == NULL)){
        return 0;
     }
    else{
        return 1;
    }
    
}



//==============================================================================
  struct SEMQUEAUE* createSEMQUEU()
{
    SEMfront = SEMrear = NULL;
    return SEMrear;
}

/* Enqueing the queue */
void enqSEMQUEU(void* data)
{

    if (SEMrear == NULL)
    {
        SEMrear = (struct SEMQUEAUE *)malloc(sizeof(struct SEMQUEAUE));
        SEMrear->ptr = NULL;
        SEMrear->info = (void*)data;
        SEMfront = SEMrear;
    }
    else
    {
        SEMtemp=(struct SEMQUEAUE *)malloc(1*sizeof(struct SEMQUEAUE));
        SEMrear->ptr = SEMtemp;
        SEMtemp->info = (void*)data;
        SEMtemp->ptr = NULL;
        SEMrear = SEMtemp;
    }
}


void *deqSEMQUEU()
{
    void *SEMtmp;
    SEMfront1 = SEMfront;
    
    if (SEMfront1 == NULL)
    {
        return (int *)-1;
    }
    else
        if (SEMfront1->ptr != NULL)
        {
            SEMfront1 = SEMfront1->ptr;
            SEMtmp=SEMfront->info;
            free(SEMfront);
            SEMfront = SEMfront1;
        }
        else
        {
            SEMtmp=SEMfront->info;
            free(SEMfront);
            SEMfront = NULL;
            SEMrear = NULL;
        }
        return SEMtmp;
}


/* queue is empty or not */
int emptySEMQUEU()
{
    int boolean=0;
     if ((SEMfront == NULL) && (SEMrear == NULL)){
        return 0;
     }
    else{
        return 1;
    }
    
}

