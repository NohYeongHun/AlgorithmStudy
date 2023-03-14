CC = clang++
CFLAGS = -std=c++17 -stdlib=libc++ -g


all: main

main : main.cpp std_main1.o grade.o core.o Student_info.o 
	$(CC) $(CFLAGS) -o main std_main1.o grade.o core.o Student_info.o 

std_main1.o: std_main1.cpp Handle.h Student_info.h
	$(CC) $(CFLAGS) -c std_main1.cpp

Student_info.o : Student_info.cc core.h Student_info.h
	$(CC) $(CFLAGS) -c Student_info.cc

grade.o : grade.cc grade.h median.h
	$(CC) $(CFLAGS) -c grade.cc

core.o : core.cc core.h grade.h
	$(CC) $(CFLAGS) -c core.cc

clean:
	rm -f main *.o 