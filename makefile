CC=g++
LIBS = -ltiff -L/usr/lib/x86_64-linux-gnu/ -fPIC
MX=mex

cinereaderinterface.mex: matlab/CineReaderInterface.cpp cinereader.o cineimage.o imageoffsets.o bitmapinfoheader.o cinefileheader.o bitreader.o
	$(MX) matlab/CineReaderInterface.cpp *.o  -output matlab/CineReaderInterface

cinereader.o: cinereader.cpp cinereader.h data.h
	$(CC) $(LIBS) -c cinereader.cpp

cineimage.o: cineimage.cpp cineimage.h data.h
	$(CC) $(LIBS) -c cineimage.cpp

imageoffsets.o: imageoffsets.h imageoffsets.cpp data.h
	$(CC) $(LIBS) -c imageoffsets.cpp

bitmapinfoheader.o: bitmapinfoheader.cpp bitmapinfoheader.h data.h 
	$(CC) $(LIBS) -c bitmapinfoheader.cpp 

cinefileheader.o: cinefileheader.cpp cinefileheader.h data.h 
	$(CC) $(LIBS) -c cinefileheader.cpp 

bitreader.o: bitreader.cpp bitreader.h data.h
	$(CC) $(LIBS) -c bitreader.cpp 



all: cinereader.o cineimage.o imageoffsets.o bitmapinfoheader.o cinefileheader.o bitreader.o

test: test.cpp data.h bitreader.o cinefileheader.o bitmapinfoheader.o imageoffsets.o cineimage.o cinereader.o
	$(CC) imageoffsets.o bitreader.o cinefileheader.o bitmapinfoheader.o cineimage.o cinereader.o test.cpp -o test $(LIBS)


run: test
	./test

clean:
	mv *.o /tmp