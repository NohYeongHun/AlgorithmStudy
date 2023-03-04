CC = clang++ 
CFLAGS = -std=c++17 --stdlib=libc++ -g

all : main

main : imporvement.o
	$(CC) $(CFLAGS) -o main imporvement.o

imporvement.o: imporvement.cpp split.h
	$(CC) $(CFLAGS) -c imporvement.cpp

clean:
	- rm -f main *.o