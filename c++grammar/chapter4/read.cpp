#include <iomanip>
using std::istream;

istream& read(istream& is, Student_info& s)
{   
    // 학생 이름, 중간성적 및 기말성적 읽고 저장.
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework); // 학생의 모든 과제성적 읽고 저장;
    return is;
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