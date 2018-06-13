#include "thread.h"



void _BEGINMONITOR() {;}

int number_of_threads,thread_id;
Thread *common;
Thread *tmp;


extern void Thread_init(void){
   
    
    common=(Thread*)malloc(sizeof(char)*1024*32);
    common->sp=malloc(sizeof(char)*1024*32);
    common->thread_id=0;
    number_of_threads=0;
    thread_id=0;
    create();
    create_hashTable_Join();
    
    if (signal(SIGALRM, (void (*)(int))scheduling) == SIG_ERR) {
    perror("Unable to catch SIGALRM");
    exit(-1);
    }

    
    struct itimerval it_val;
    struct itimerspec its;
    timer_t timerid;
    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGALRM;
    sev.sigev_value.sival_ptr = &timerid;
    if(timer_create(CLOCK_REALTIME, &sev, &timerid)==-1){
        perror("timer_create failed:\n");
        exit(-1);
    }
    
    its.it_value.tv_sec =0; 
    its.it_value.tv_nsec =1000000;
    its.it_interval.tv_sec = its.it_value.tv_sec;
    its.it_interval.tv_nsec = its.it_value.tv_nsec;
    timer_settime(timerid, 0, &its, NULL);
    

}

int scheduling(void) {
    sigset_t  oldMask;
    sigprocmask(SIG_SETMASK, &oldMask, NULL);
    Thread_pause();
}
 

extern int Thread_new(int func(void *), void *args, size_t nbytes, ...){
    Thread *t,*cc,*pp;
    number_of_threads++;
    extern void  _thrstart(void);


    t=(Thread*)malloc(sizeof(char)*32*1024);
    t->sp =(int*)malloc(sizeof(char)*32*1024);
    t->thread_id=thread_id;
    thread_id++;
    t->copy_of_values_args=malloc(nbytes);
 
    memcpy(t->copy_of_values_args,args,nbytes);
      t->sp=(t->sp+((32*1024)/4));
     *t->sp=(unsigned long)_thrstart;
      t->sp=t->sp-2;
     *t->sp-- =(unsigned long)t->copy_of_values_args;
     *t->sp-- =(unsigned long)func;
   
    enq(t);
    return thread_id-1;
}




extern void Thread_exit(int code){
    int has_joined_thread=0;
    --number_of_threads;
   
    if( number_of_threads==-1 )
        exit(code);
/*
*   if readyqueue doesn't have more threads we must
*   check join hashTable if has thread waiting
*/   
    if(empty()==0){
        /*
         * check join for thread 0 if we had called Thread_join(0) in user 
         * program
         */
       
        has_joined_thread=searchInHashTable_Join(0);
        if(has_joined_thread==1){
            put_from_Join_to_readyqueue(0);
            tmp=common;
            common=deq();
            _swtch(tmp,common);
        }
        /*
         * check join for common thread if has thread waiting for him to finish 
         */
        
        has_joined_thread=searchInHashTable_Join(common->thread_id);
        if(has_joined_thread==1){
            put_from_Join_to_readyqueue(common->thread_id);
            tmp=common;
            common=deq();
            _swtch(tmp,common);
        }
/*
*  
*   check common thread_exit if has other thread that wait for him 
*   if yes put in readyqueue  
*/     
    }else{
        has_joined_thread=searchInHashTable_Join(common->thread_id);
        if(has_joined_thread==1){
            if(common->thread_id!=0)
            put_from_Join_to_readyqueue(common->thread_id);
            
        }
        tmp=common;
        common=deq();
        _swtch(tmp,common);
        }
    
}

extern int Thread_self(void){
    return common->thread_id;
}


extern int Thread_join(int tid){
    /*
     * put common thread in join hashTable to wait 
     * for finishing the thread tid and take next 
     * thread from readyqueue to take cpu
     */
   insertToHashTable_Join(tid,common);
   tmp=common;
   common=deq();
   _swtch(tmp,common);
    return 0;
}

extern void Thread_pause(void){
    enq(common);
    tmp=common;
    common=deq();
    _swtch(tmp,common);
}
