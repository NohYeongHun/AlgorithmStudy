#include<iostream>
#include<ios>
#include<iomanip>
#include<vector>
#include<algorithm>

using namespace std;
/*
    Student_info 구조체 작성
    성적을 바로 계산하여 최종성적만 저장하는 프로그램 작성.
*/

struct Student_info{
    string name;
    double final_grade;
};

double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
 
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
 
    sort(vec.begin(),vec.end());
 
    vec_sz mid = size/2;
 
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
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

istream& read(istream& is, Student_info& s)
{
    double midterm;
    double final;
    vector<double> homework;
 
    is >> s.name >> midterm >> final;
 
    // read and store all the student's homework scores (to the temporary vector<double> container)
    read_hw(is, homework);
 
    // compute the student's overall score, and store to the Student_info object
    try
    {
        s.final_grade = grade(midterm, final, homework);
    }
    catch (domain_error e)
    {
        s.final_grade = -1;  // indicating student has done no homework
    }
    return is;
}

int main(){

    vector<Student_info> students;
    Student_info s;
    while(read(cin, s)){
        students.push_back(s);
    }
    
    for (vector<Student_info>::size_type i = 0; i!= students.size(); i++){
        cout << "현재 학생 이름 = " << students[i].name << "| 현재 학생 최종 성적 = " << students[i].final_grade << "\n";
    }
}