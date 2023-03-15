CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g

all : main

main : main.cpp histo.o Student_info.o Core.o Pic.o grade.o
	$(CC) $(CFLAGS) -o main histo.o Student_info.o Core.o Pic.o grade.o

histo.o: histo.cpp Core.h Pic.h Student_info.h
	$(CC) $(CFLAGS) -c histo.cpp

Student_info.o: Student_info.cpp Student_info.h Core.h
	$(CC) $(CFLAGS) -c Student_info.cpp

Core.o: Core.cpp Core.h grade.h
	$(CC) $(CFLAGS) -c Core.cpp

grade.o: grade.cpp grade.h median.h
	$(CC) $(CFLAGS) -c grade.cpp

Pic.o: Pic.cpp Pic.h
	$(CC) $(CFLAGS) -c Pic.cpp 

clean:
	rm -f main *.o