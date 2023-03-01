CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g

all: paragraphs

paragraphs: frame.o vcat.o hcat.o main.o
	$(CC) $(CFLAGS) -o paragraphs frame.o vcat.o hcat.o main.o

frame.o: frame.cpp frame.h
	$(CC) $(CFLAGS) -c frame.cpp

vcat.o: vcat.cpp vcat.h
	$(CC) $(CFLAGS) -c vcat.cpp
	
hcat.o: hcat.cpp hcat.h
	$(CC) $(CFLAGS) -c hcat.cpp

main.o: main.cpp frame.h vcat.h hcat.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f paragraphs *.o