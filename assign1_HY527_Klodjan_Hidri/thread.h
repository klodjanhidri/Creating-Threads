/*
    Klodjan Hidri
    AM2726
 */
#ifndef THREAD_INCLUDED
#define THREAD_INCLUDED

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include </usr/include/signal.h>
#include <sys/time.h>
#include <inttypes.h>
#include "join_hashTable.h"
#include <signal.h>
#include <time.h>
#include <unistd.h>


extern Thread *common;
extern Thread *tmp;
extern void _MONITOR();
extern void _ENDMONITOR();
extern void _swtch(void*,void*);
extern void Thread_init(void);
extern int Thread_new(int func(void *), void *args, size_t nbytes, ...);
extern void Thread_exit(int code);
extern int Thread_self(void);
extern int Thread_join(int tid);
extern void Thread_pause(void);
int scheduling(void);
#endif

