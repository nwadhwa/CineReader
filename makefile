CC=g++
LIBS = -ltiff -L/usr/lib/x86_64-linux-gnu/ -g

cinereader.o: cinereader.cpp cinereader.h data.h
	$(CC) $(LIBS) -c cinereader.cpp

cineimage.o: cineimage.cpp cineimage.h data.h
	$(CC) $(LIBS) -c cineimage.cpp

imageoffsets.o: imageoffsets.h imageoffsets.cpp data.h
	$(CC) $(LIBs) -c imageoffsets.cpp

bitmapinfoheader.o: bitmapinfoheader.cpp bitmapinfoheader.h data.h 
	$(CC) $(LIBs) -c bitmapinfoheader.cpp 

cinefileheader.o: cinefileheader.cpp cinefileheader.h data.h 
	$(CC) $(LIBs) -c cinefileheader.cpp 

bitreader.o: bitreader.cpp bitreader.h data.h
	$(CC) $(LIBS) -c bitreader.cpp 

test: test.cpp data.h bitreader.o cinefileheader.o bitmapinfoheader.o imageoffsets.o cineimage.o cinereader.o
	$(CC) imageoffsets.o bitreader.o cinefileheader.o bitmapinfoheader.o cineimage.o cinereader.o test.cpp -o test $(LIBS)

run: test
	./test