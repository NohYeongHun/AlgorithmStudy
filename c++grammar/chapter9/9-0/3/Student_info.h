#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H

#include<iostream>
#include<string>
#include<vector>
#include "grade.h"

class Student_info {
public:
    Student_info(); // 빈 Student_info 객체 생성
    Student_info(std::istream&); // 스트림 읽어서 생성
    
    // 인터페이스는 여기에
    double grade() const;
    bool valid() const { return !homework.empty(); }
    std::istream& read(std::istream&);    // 수정해야 함.
    std::string name() const {return n; } // 추가됨. 
private:
    // 구현은 여기에
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};

std::istream &read_hw(std::istream&, std::vector<double>& hw);
bool compare(const Student_info&, const Student_info&);
#endif