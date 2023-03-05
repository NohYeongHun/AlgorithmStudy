#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H

#include<iostream>
#include<string>
#include<vector>
#include "grade.h"

struct Student_info
{
    /* data */
    std::string name;
    double midterm, final;
    std::vector<double> homework;

    std::istream& read(std::istream&); // 추가됨
    double grade() const; //추가됨
};

std::istream &read_hw(std::istream& in, std::vector<double>& hw);
bool compare(const Student_info&, const Student_info&);
#endif