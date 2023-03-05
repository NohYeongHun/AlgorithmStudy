#include <string>
#include <iostream>

using std::string;
using std::cout;

string letter_grade(double grade){
    // 숫자 성적을 위한 범위 기준치
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };

    // 문자 성적을 표시할 이름
    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    // 배열의 크기가 주어졌을 때, 성적들의 개수와
    // 한 요소의 크기 계산
    static const size_t nGrades = sizeof(numbers) / sizeof(*numbers);

    // 숫자 성적이 주어졌을 때, 해당 문자 성적을 찾아서 리턴.
    for(size_t i = 0; i < nGrades; ++i){
        if(grade >= numbers[i])
            return letters[i];
    }

    return "?\?\?";
}

int main(){
    double grade = -0.5f;

    cout << "grade = " << letter_grade(grade);


    string s("Hello");
    const char* p = s.c_str();
    cout << '\n';
    cout << "*p = " << *p;
    



}