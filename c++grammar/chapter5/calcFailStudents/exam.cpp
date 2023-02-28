#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
 
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::list;

/*
    1. 전체 Chapter 4 프로젝트의 복사본을 만듭니다. 즉 연습 문제 4-0의 솔루션 에 따른 프로젝트입니다 .

    2. C++ 소스 파일 extract_fails.cpp를 추가합니다. 여기에는 extract_fail 함수의 4가지 버전이 포함되어 있습니다. 
    나중에 쉽게 테스트할 수 있도록 함수 4개만 생성합니다. 
    즉: extract_fails_v1 , extract_fails_v2 , extract_fails_v3 , extract_fails_v4 . 함수 fgrade 도 이 파일에 저장됩니다.

    3. 해당 C++ 헤더 파일을 추가합니다. 즉 extract_fails.h.
    
    4. 테스트에 적합하도록 main 함수를 조정합니다. 
    extract_fail 버전 1, 2 및 3은 vector<Student_info> 컨테이너를 사용하는 반면 버전 4는 list<Student_info> 컨테이너를 사용합니다. 
    이 때문에 테스트 를  위한 두 가지 버전 의 기본 프로그램이 있습니다 .
*/
int main(){

    list<Student_info> students;
    list<Student_info> failStudents;
    Student_info s;
    while(read_st(cin, s)){
        students.push_back(s);
    }
    
    for (list<Student_info>::iterator iter = students.begin(); iter!= students.end(); iter++){
        cout << "현재 학생 이름 = " << iter -> name << "| 현재 학생 최종 성적 = " << iter -> finalGrade << "\n";
    }

    cout << "탈락자 소거" << "\n";
    failStudents = extract_fails(students);

    for (list<Student_info>::iterator iter = students.begin(); iter!= students.end(); iter++){
        cout << "현재 학생 이름 = " << iter -> name << "| 현재 학생 최종 성적 = " << iter -> finalGrade << "\n";
    }

    cout << "\n";
    for (list<Student_info>::iterator iter = failStudents.begin(); iter!= failStudents.end(); iter++){
        cout << "탈락 학생 이름 = " << iter -> name << "| 탈락 학생 최종 성적 = " << iter -> finalGrade << "\n";
    }
    
    return 0;
}