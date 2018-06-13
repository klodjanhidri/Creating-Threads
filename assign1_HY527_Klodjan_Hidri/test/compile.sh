ln -s ../thread.h .
ln -s ../sem.h .
ln -s ../chan.h .
ln -s ../join_hashTable.h .
ln -s ../queus.h .
cd ../ && make all 	#paragwgh tou thread.a
cp thread.a test/

cd test/
make sieve
make sieve2
make sieve4
make sink
make sort
make spin
make spin2
make spin3
