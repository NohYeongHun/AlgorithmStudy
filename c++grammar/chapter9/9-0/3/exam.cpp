#include "grade.h"
#include "Student_info.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::streamsize;
using std::setprecision;
using std::domain_error;
using std::max;

int main(){

    Student_info record;
    vector<Student_info> students;
    string::size_type maxlen = 0;

    // 데이터를 읽고 저장.
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size()); // 수정됨
        students.push_back(record);
    }

    // 학생 레코드들을 알파벳순으로 정렬합니다.
    sort(students.begin(), students.end(), compare);

    // 이름과 성적 출력
    for (vector<Student_info>::size_type i = 0;
        i != students.size(); ++i) {
            cout << students[i].name()
                << string(maxlen + 1 - students[i].name().size(), ' ');

            try{
                double final_grade = students[i].grade(); // 수정됨
                streamsize prec = cout.precision();
                cout << setprecision(3) << final_grade
                     << setprecision(prec) << endl;
            } catch (domain_error e) {
                cout << e.what() << endl;
            }
        }
    
    return 0;
}