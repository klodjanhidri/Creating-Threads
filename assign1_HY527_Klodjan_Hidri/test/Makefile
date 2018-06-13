sieve:
	 gcc -m32 sieve.c   thread.a -lrt -o sieve 

sieve2:
	gcc -m32 sieve2.c  thread.a -lrt -o sieve2

sieve4:  
	gcc -m32 sieve4.c  thread.a -lrt  -o sieve4

sink: 
	gcc -m32 sink.c thread.a -lrt  -o sink

sort: 
	gcc -m32 sort.c  thread.a -lrt  -o sort

spin: 
	gcc -m32 spin.c thread.a -lrt -o spin 

spin2: 
	gcc -m32 spin2.c  thread.a -lrt -o spin2

spin3: 
	gcc -m32 spin3.c  thread.a -lrt  -o spin3

clean: 
		rm -rf chan.h sink sieve sieve2 sieve4 sort spin spin2 spin3 thread.a  thread.o queus.o join_hashTable.o sem.o swtch.o chan.o sieve.o  a.out join_hashTable.h queus.h  sem.h thread.h  assign1_HY527
