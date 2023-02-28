#ifndef GUARD_GRADE_H
#define GUARD_GRADE_H

//grade.h
#include <stdexcept>
#include <vector>
#include "median.h"
#include "Student_info.h"
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fGrade(const Student_info&);
#endif