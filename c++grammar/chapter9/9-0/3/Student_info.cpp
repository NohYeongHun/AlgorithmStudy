#include "Student_info.h"
#include "grade.h"
 
using std::istream;
using std::vector;

Student_info::Student_info() : midterm(0), final(0) { }
Student_info::Student_info(istream& is) {read(is);}

istream& Student_info::read(istream& in)
{
    // read and store the student's name and midterm and final exam grades
    in >> n >> midterm >> final;
 
    // read and store all the student's homework grades
    read_hw(in, homework);
    return in;
}

double Student_info::grade() const
{
    return ::grade(midterm, final, homework);
}

istream& read_hw(istream& in, vector<double>& hw)
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

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}
