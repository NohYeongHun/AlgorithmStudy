CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g

all: main

main: frame.o hcat.o Permuted_index.o read_lines.o split.o vcout.o main_make.o
	$(CC) $(CFLAGS) -o main frame.o hcat.o Permuted_index.o read_lines.o split.o vcout.o main_make.o

frame.o: frame.cpp frame.h
	$(CC) $(CFLAGS) -c frame.cpp

hcat.o : hcat.cpp hcat.h
	$(CC) $(CFLAGS) -c hcat.cpp

vcout.o : vcout.cpp vcout.h
	$(CC) $(CFLAGS) -c vcout.cpp

split.o : split.cpp split.h
	$(CC) $(CFLAGS) -c split.cpp

read_lines.o : read_lines.cpp read_lines.h
	$(CC) $(CFLAGS) -c read_lines.cpp

Permuted_index.o : Permuted_index.cpp Permuted_index.h split.h
	$(CC) $(CFLAGS) -c Permuted_index.cpp

main_make.o: main_make.cpp frame.h hcat.h Permuted_index.h read_lines.h split.h vcout.h
	$(CC) $(CFLAGS) -c main_make.cpp

clean:
	rm -f main *.o