CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g


all: main

main : main.cpp std_main1.o Pic.o Str.o
	$(CC) $(CFLAGS) -o main std_main1.o Pic.o Str.o

std_main1.o: std_main1.cpp Pic.h
	$(CC) $(CFLAGS) -c std_main1.cpp

Pic.o: Pic.cpp Pic.h Ptr.h Str.h Vec.h
	$(CC) $(CFLAGS) -c Pic.cpp

Str.o: Str.cpp Str.h
	$(CC) $(CFLAGS) -c Str.cpp


clean:
	rm -f main *.o 