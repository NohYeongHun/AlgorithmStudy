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

int main(){

    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // 학생들의 모든 데이터를 읽고 저장.
    while(read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // 레코드들을 알파벳 순으로 정렬
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; 
        i != students.size(); ++i){

        // 오른쪽에 maxlen + 1 개의 공백문자를 포함한 이름을 출력
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');

        // 성적을 계산하고 출력
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        } catch(domain_error e){
            cout << e.what();
        }
        cout << endl;
    }
    
    return 0;
}