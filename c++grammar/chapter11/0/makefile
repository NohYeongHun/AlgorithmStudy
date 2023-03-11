CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g

all: main

main: main.cpp exam.o
	$(CC) $(CFLAGS) -o main exam.o

exam.o: exam.cpp vec.h
	$(CC) $(CFLAGS) -c exam.cpp

clean:
	rm -f main *.o