CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g

all: main

main: test.o read_grammar.o split.o gen_sentence.o nrand.o gen_aux.o
	$(CC) $(CFLAGS) -o main test.o read_grammar.o split.o gen_sentence.o nrand.o gen_aux.o

test.o: test.cpp read_grammar.h gen_sentence.h
	$(CC) $(CFLAGS) -c test.cpp

read_grammar.o : read_grammar.cpp split.h read_grammar.h
	$(CC) $(CFLAGS) -c read_grammar.cpp

split.o : split.cpp split.h
	$(CC) $(CFLAGS) -c split.cpp

gen_sentence.o : gen_sentence.cpp gen_sentence.h read_grammar.h gen_aux.h
	$(CC) $(CFLAGS) -c gen_sentence.cpp

gen_aux.o : gen_aux.cpp read_grammar.h nrand.h
	$(CC) $(CFLAGS) -c gen_aux.cpp

nrand.o : nrand.cpp nrand.h
	$(CC) $(CFLAGS) -c nrand.cpp

clean:
	- rm -f main *.o