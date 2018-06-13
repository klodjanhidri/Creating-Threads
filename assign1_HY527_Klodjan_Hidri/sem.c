/*
    Klodjan Hidri
    AM2726
 */
#include "sem.h"

#define T Sem_T

  void Sem_init(T *s, int count){
        s->count=count;
        s->queue=createSEMQUEU();
}

void Sem_wait(T *s){
    while (s->count <= 0);
    s->count=s->count-1;
}

 void Sem_signal(T *s){
     s->count=s->count+1;
    
}

