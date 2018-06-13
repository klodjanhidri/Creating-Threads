/*
    Klodjan Hidri
    AM2726
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct Thread{
    int *sp;
    unsigned int thread_id;
    unsigned int *copy_of_values_args;
}Thread;

struct READYQUEAUE
{
    void *info;
    struct READYQUEAUE *ptr;
}*front,*rear,*temp,*front1;



struct SEMQUEAUE
{
    void *info;
    struct SEMQUEAUE *ptr;
}*SEMfront,*SEMrear,*SEMtemp,*SEMfront1;




extern struct READYQUEAUE*  create();
extern void enq(void *t);
extern void *deq();
extern int empty(); 


extern struct SEMQUEAUE* createSEMQUEU();
void enqSEMQUEU(void* data);
extern void *deqSEMQUEU();
extern int emptySEMQUEU();

