CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g

all: main

main : main.cpp Str_test.o
	$(CC) $(CFLAGS) -o main Str_test.o

Str_test.o: Str_test.cpp vec.h str.h
	$(CC) $(CFLAGS) -c Str_test.cpp

clean:
	rm -f main *.o