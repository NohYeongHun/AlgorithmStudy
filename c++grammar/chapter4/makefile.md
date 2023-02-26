# makefile 설정

```make
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
```
- `CC` = clang++: 변수 CC를 사용할 컴파일러 명령인 clang++로 설정합니다.
- `CFLAGS = -std=c++17 -stdlib=libc++ -g`: CFLAGS 변수를 사용할 컴파일러 플래그로 설정하며 여기에는 C++17 표준, libc++ 라이브러리 및 디버깅 기호가 포함합니다.
- `all: exam_final`: 이것은 기본 규칙으로, exam_final 대상을 구성합니다. all은 파일의 첫 번째 규칙이므로 대상을 지정하지 않고 make를 실행할 때 실행되는 기본 규칙입니다.
- `exam_final: Student_info.o grade.o median.o main.o`: 이 규칙은 exam_final이 Student_info.o, grade.o, median.o 및 main.o의 네 가지 개체 파일에 종속되도록 지정합니다.
- `$(CC) $(CFLAGS) -o exam_final Student_info.o grade.o median.o main.o`: 이것은 exam_final 실행 파일을 빌드하는 명령입니다. 지정된 플래그와 함께 clang++ 컴파일러를 사용하여 4개의 개체 파일을 함께 연결하고 exam_final 실행 파일을 만듭니다.
- `Student_info.o: Student_info.cpp Student_info.h`: 이 규칙은 Student_info.o가 Student_info.cpp 및 Student_info.h에 종속됨을 지정합니다.
- `$(CC) $(CFLAGS) -c Student_info.cpp`: Student_info.cpp를 오브젝트 파일로 컴파일하는 명령입니다. 지정된 플래그와 함께 clang++ 컴파일러를 사용하여 Student_info.cpp에서 개체 파일을 생성합니다.
- `grade.o: grade.cpp grade.h median.h Student_info.h`: 이 규칙은 grade.o가 grade.cpp, grade.h, median.h 및 Student_info.h에 종속됨을 지정합니다.
- `$(CC) $(CFLAGS) -c grade.cpp`: grade.cpp를 오브젝트 파일로 컴파일하는 명령입니다. 지정된 플래그와 함께 clang++ 컴파일러를 사용하여 grade.cpp에서 개체 파일을 생성합니다.
- `median.o: median.cpp median.h`: 이 규칙은 median.o가 median.cpp 및 median.h에 종속되도록 지정합니다.
- `$(CC) $(CFLAGS) -c median.cpp`: 이것은 median.cpp를 오브젝트 파일로 컴파일하는 명령입니다. 지정된 플래그와 함께 clang++ 컴파일러를 사용하여 median.cpp에서 개체 파일을 만듭니다.
- `main.o`: main.cpp Student_info.h grade.h: 이 규칙은 main.o가 main.cpp, Student_info.h 및 grade.h에 종속되도록 지정합니다.
- `$(CC) $(CFLAGS) -c main.cpp`: main.cpp를 오브젝트 파일로 컴파일하는 명령입니다. 이는 지정된 플래그와 함께 clang++ 컴파일러를 사용하여 main.cpp에서 개체 파일을 생성합니다.
- `clean: rm -f exam_final *.o`: 이 규칙은 빌드 아티팩트를 정리하는 방법을 지정합니다. 그것은 exam_final 실행 파일과 모든 개체 파일을 제거합니다.