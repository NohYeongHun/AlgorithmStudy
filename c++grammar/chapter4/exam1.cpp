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
using std::setprecision;

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

int main(){

    // 학생의 이름을 요청하고 읽어들임
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // 중간고사와 기말고사 성적을 묻고 읽어들임
    cout << "Please enter your midterm and final size exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // 과제 성적 요청
    cout << "Enter all your homework grades,"
            "followed by endoffile: ";

    vector<double> homework;
    // 과제 성적을 읽어들임
    read_hw(cin, homework);

    // 최종 성적을 계산하고, 가능한 경우 출력
    try {
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << final_grade << setprecision(prec) << endl;
    } catch (domain_error){
        cout << endl << "You must enter your grades. "
                "Please try again." << endl;
        return 1;
    }
    return 0;
}