all: cropBmp

cropBmp: main.o Bitmap.o
	g++ -o cropBmp main.o Bitmap.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

Bitmap.o: Bitmap.cpp
	g++ -c -o Bitmap.cpp

clean:
	rm -rf *o cropBmp