CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g


all: main

main : main.cpp exam.o grade.o core.o Student_info.o 
	$(CC) $(CFLAGS) -o main exam.o grade.o core.o Student_info.o 

exam.o: exam.cpp Student_info.h
	$(CC) $(CFLAGS) -c exam.cpp

Student_info.o : Student_info.cc core.h Student_info.h
	$(CC) $(CFLAGS) -c Student_info.cc

grade.o : grade.cc grade.h median.h
	$(CC) $(CFLAGS) -c grade.cc

core.o : core.cc core.h grade.h
	$(CC) $(CFLAGS) -c core.cc



clean:
	rm -f main *.o 