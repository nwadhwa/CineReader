CC=g++

test: test.cpp data.h
	$(CC) test.cpp -o test