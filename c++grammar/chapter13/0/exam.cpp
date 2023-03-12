#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"

using namespace std;

int main() {
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;
  
  // 데이터 읽고 저장
  /*
    1. Student_info.cc read()
    2. is(cin) >> ch(char Type) : 학생의 타입 결정 Core Type or Grade or ...
    3. type에 맞는 학생의 생성자 생성 ex) cp = new Core(is); 
    => Core type의 cp pointer에 new 를 통해 생성된 Core 객체를 대입한다.
    4. Core(is) : 현재 학생의 타입을 들고있는 input stream인 is를 Core의 생성자에
    매개변수로 넣어준다.
    5. Core(std::istream& is) { read(is); }
    => input stream인 is가 오게되면 read함수에 input stream is가 넣어지고 호출된다.
    6. read_common(in)
    => 학생의 이름, 중간, 기말 성적을 기입한다.
    7. read_hw(in, homework)
    => 학생의 과제성적 기입
    8. Core 클래스의 private 변수에 값이 채워진다.
    std::string n;
    double midterm, final;  
    std::vector<double> homework;
    std::istream& read_common(std::istream&);
  */
  while (record.read(cin)) {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  // 학생 레코드를 알파벳 순으로 정렬
  sort(students.begin(), students.end(), Student_info::compare);

  // 이름과 성적을 출력
  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    cout << students[i].name()
	 << string(maxlen + 1 - students[i].name().size(), ' ');

    try {
      double final_grade = students[i].grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
	   << setprecision(prec) << endl;
    } catch (domain_error e) {
      cout << e.what() << endl;
    }
  }

  return 0;
}