all: thread.a

thread.a: thread.o join_hashTable.o queus.o sem.o chan.o swtch.o
		ar rcs $@ $^

thread.o: thread.c thread.h
		gcc -g -m32 -lrt -c thread.c -o thread.o

join_hashTable.o: join_hashTable.c join_hashTable.h
		gcc -g -m32 -lrt -c join_hashTable.c  -o join_hashTable.o

queus.o: queus.c queus.h
		gcc -g -m32 -lrt -c queus.c -o queus.o

sem.o: sem.c sem.h 
		gcc -g -m32 -lrt -c sem.c -o sem.o

chan.o: chan.c chan.h  
		gcc -g -m32 -lrt -c chan.c -o chan.o

swtch.o: swtch.S 
		gcc -m32 -c swtch.S -o swtch.o



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
		rm -f sink sieve sieve2 sieve4 sort spin spin2 spin3 thread.a  thread.o queus.o join_hashTable.o sem.o swtch.o chan.o sieve.o  a.out
