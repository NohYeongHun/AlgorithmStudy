#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>

using std::ifstream;
using std::ofstream;
using std::string;
using std::getline;
using std::cout;
using std::endl;
using std::cerr;

/*
    1. compile
    2. command 
    clang++ -o main streamTest.cpp
*/
int main(int argc, char**argv)
{
    int failCount = 0;
    // 입력 리스트의 각 파일에 대하여
    for(int i = 1; i < argc; ++i){
        ifstream in(argv[i]);

        // 만약 있다면 그 내용을 출력하고, 그렇지 않다면 에러 메시지를 출력
        if (in) {
            string s;
            while (getline(in ,s))
                cout << s << endl;
        } else {
            cerr << "cannot open file " << argv[i] << endl;
            ++failCount;
        }
    }
    return failCount;
}