CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g

all: main

main: main.cpp exam.o Student_info.o grade.o median.o 
	$(CC) $(CFLAGS) -o main exam.o Student_info.o grade.o median.o

exam.o: exam.cpp Student_info.h grade.h
	$(CC) $(CFLAGS) -c exam.cpp

Student_info.o: Student_info.cpp Student_info.h grade.h
	$(CC) $(CFLAGS) -c Student_info.cpp

grade.o: grade.cpp grade.h median.h
	$(CC) $(CFLAGS) -c grade.cpp

median.o: median.cpp median.h
	$(CC) $(CFLAGS) -c median.cpp

clean:
	rm -f main *.o