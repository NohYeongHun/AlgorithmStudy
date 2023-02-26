CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g

all: exam_final

exam_final: Student_info.o grade.o median.o main.o
	$(CC) $(CFLAGS) -o exam_final Student_info.o grade.o median.o main.o

Student_info.o: Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) -c Student_info.cpp

grade.o: grade.cpp grade.h median.h Student_info.h
	$(CC) $(CFLAGS) -c grade.cpp

median.o: median.cpp median.h
	$(CC) $(CFLAGS) -c median.cpp

main.o: main.cpp Student_info.h grade.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f exam_final *.o