#include<iostream>
#include<fstream>
#include<string>

using std::ifstream;
using std::ofstream;
using std::string;
using std::getline;
using std::endl;

/*
    clang++ -o say main.cpp
    => main.cpp 파일을 이용하여 say라는 오브젝트 실행파일 생성.
*/
int main()
{
    ifstream infile("input.txt");
    ofstream outfile("out.txt");

    string s;
    while (getline(infile, s))
        outfile << s << endl;
    return 0;
}