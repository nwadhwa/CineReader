CC=g++

bitreader.o: bitreader.cpp bitreader.h data.h
	$(CC) -c bitreader.cpp 

test: test.cpp data.h bitreader.o
	$(CC) bitreader.o test.cpp -o test

run: test
	./test