#include "Student_info.h"
#include "grade.h"
 
using std::istream;
using std::vector;
using std::list;
using std::domain_error;
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read_st(istream& is, Student_info& s)
{
    double midterm;
    double final;
    vector<double> homework;
 
    is >> s.name >> midterm >> final;
 
    // read and store all the student's homework scores (to the temporary vector<double> container)
    read_st_hw(is, homework);
 
    // compute the student's overall score, and store to the Student_info object
    try
    {
        s.finalGrade = grade(midterm, final, homework);
    }
    catch (domain_error e)
    {
        s.finalGrade = -1;  // indicating student has done no homework
    }
    return is;
}


istream &read_st_hw(istream& in, vector<double>& hw)
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

/*
    이수한 학생과 이수하지 못한 학생 분리 : version 1
    vector<Student_info> extract_fails(vector<Student_info>& students)
    {
        vector<Student_info>pass, fail;
        for (vector<Student_info>::size_type i = 0;
                i != students.size(); ++i){
                    if(fGrade(students[i])){
                        fail.push_back(students[i]);
                    } else{
                        pass.push_back(students[i]);
                    }
                }
            students = pass;
            return fail;
                
    }
*/

/*
    이수한 학생과 이수하지 못한 학생 분리 : version 2
    vector<Student_info> extract_fails(vector<Student_info>& students)
    {
        vector<Student_info> fail;
        vector<Student_info>::size_type i;
        while(i != students.size()){
            if(fGrade(students[i])){
                fail.push_back(students[i]);
                students.erase(students.begin() + i);
            } else {
                ++i;
            }
        }
        return fail;       
    }
*/ 

/*
    이수한 학생과 이수하지 못한 학생 분리 : version 3
    인덱스를 전혀 사용하지 않음 : 그러나 느림.
    vector<Student_info> extract_fails(vector<Student_info>& students)
    {
        vector<Student_info> fail;
        vector<Student_info>::iterator iter = students.begin();
        while(iter != students.end()) {
            if (fGrade(*iter)) {
                fail.push_back(*iter);
                iter = students.erase(iter);
            } else {
                ++iter;
            }
        }

        return fail;
    }
*/

// version 4 : list 사용
list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
    while(iter!= students.end()){
        if (fGrade(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else{
            ++iter;
        }
    }
    
    return fail;
}

