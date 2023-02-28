CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g

all: splitTest

splitTest: split.o main.o
	$(CC) $(CFLAGS) -o splitTest split.o main.o
main: main.cpp split.h
	$(CC) $(CFLAGS) -c main.cpp
split.o: split.cpp split.h
	$(CC) $(CFLAGS) -c split.cpp

clean:
	rm -f splitTest *.o