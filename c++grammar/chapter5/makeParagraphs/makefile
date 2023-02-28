CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g

all: paragraphs

paragraphs: frame.o vcat.o hcat.o vcout.o main.o
	$(CC) $(CFLAGS) -o paragraphs frame.o vcat.o hcat.o vcout.o main.o

frame.o: frame.cpp frame.h
	$(CC) $(CFLAGS) -c frame.cpp

hcat.o: hcat.cpp hcat.h
	$(CC) $(CFLAGS) -c hcat.cpp

vcat.o: vcat.cpp vcat.h
	$(CC) $(CFLAGS) -c vcat.cpp

vcout.o: vcout.cpp vcout.h
	$(CC) $(CFLAGS) -c vcout.cpp

main.o: main.cpp frame.h frame.h hcat.h vcat.h vcout.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f paragraphs *.o