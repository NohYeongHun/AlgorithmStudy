#include <algorithm>
#include <iostream>

#include "Core.h"
#include "Pic.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

Picture histogram(const vector<Student_info>& students)
{
	Picture names;
	Picture grades;

	// for each student
	for (vector<Student_info>::const_iterator it = students.begin();
	     it != students.end(); ++it) {

		// create vertically concatenated pictures of the names and grades
		names = vcat(names, vector<string>(1, it->name()));
		grades = vcat(grades,
		    vector<string>(1, " " + string(it->grade() / 5, '=')));
	}

	// horizontally concatenate the name and grade pictures to combine them
	return hcat(names, grades);
}

int main()
{
	vector<Student_info> students;
	Student_info s;

	// read the names and grades
	while (s.read(cin))
		students.push_back(s);

	// put the students in alphabetical order
	sort(students.begin(), students.end(), Student_info::compare);

	// write the names and histograms
	cout << frame(histogram(students)) << endl;
	return 0;
}