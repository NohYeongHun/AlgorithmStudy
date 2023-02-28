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