#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
// vector 컨테이너 import
#include <vector>
// sort 함수를 사용하기 위한 헤더 import
#include <algorithm>

using std::vector; using std::istream;
using std::cin;  using std::string;
using std::cout; using std::endl;
using std::domain_error; using std::streamsize;
using std::setprecision; using std::max;

double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    
    sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (vec[mid] + vec[mid]) / 2 : vec[mid];
}

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// 여기 const vector<double>& hw 는 들어오는 vector<double> 타입 변수에 대한 별칭이다.
// 쓰기 권한이 없는 별칭이다. => 값을 변경할 수 없다.
// method overloading
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");

    return grade(midterm, final, median(hw));
}

istream &read_hw(istream& in, vector<double>& hw)
{
    if(in)
    {
        // 이전 내용 삭제
        hw.clear();

        // 과제 성적을 읽어들임
        double x;
        while(in >> x)
        {
            hw.push_back(x);
        }
        // 다음 학생의 데이터를 읽을 수 있도록 스트림 모두 삭제
        in.clear();
    }
    return in;
}

struct Student_info
{
    /* data */
    string name;
    double midterm, final;
    vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{   
    // 학생 이름, 중간성적 및 기말성적 읽고 저장.
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework); // 학생의 모든 과제성적 읽고 저장;
    return is;
}


// 학생 객체에 대한 성적값 반환
double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}


int main(){

    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // 모든 레코드들을 읽고 저장하며, 가장 긴 이름의 길이를 계산
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