#include "grade.h"
#include "Student_info.h"
#include <iostream>

using std::cin;
using std::cout;
using std::vector;
int main(){
    Student_info s;
    s.read(cin);
    cout << "학생 이름 = " << s.name <<'\n';
    cout << "학생 중간 성적 = " << s.midterm << '\n';
    cout << "학생 기말 성적 = " << s.final << '\n';

    cout << "학생 과제 성적 = ";
    for(vector<double>::iterator iter = s.homework.begin(); iter!= s.homework.end(); iter++){
        cout << *iter << " ";
    }
    cout << '\n';

    
    cout << "학생 최종 성젹 = " << s.grade() << "\n";
}