CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g

all: main

main: crossReferenceTable.o xref.o split.o
	$(CC) $(CFLAGS) -o main crossReferenceTable.o xref.o split.o

crossReferenceTable.o: crossReferenceTable.cpp xref.h split.h
	$(CC) $(CFLAGS) -c crossReferenceTable.cpp

xref.o: xref.cpp xref.h split.h
	$(CC) $(CFLAGS) -c xref.cpp

split.o: split.cpp split.h
	$(CC) $(CFLAGS) -c split.cpp

clean:
	- rm -f main *.o