#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H

#include<iostream>
#include<string>
#include<vector>
#include<list>

struct Student_info
{
    /* data */
    std::string name;
    double finalGrade;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_st(std::istream&, Student_info&);
std::istream& read_st_hw(std::istream&, std::vector<double>&);
std::list<Student_info> extract_fails(std::list<Student_info>& students);
#endif