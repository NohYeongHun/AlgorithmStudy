#include<iostream>

using std::cout;
using std::endl;
/*
    clang++ -o say main.cpp
    ./say Hello world
    1. compile
    2. 실행
*/
int main(int argc, char** argv)
{
    // 만약 인자가 있다면 출력
    if(argc > 1) {
        int i; // i 를 for 밖에 선언하는 이유는 for 루프가 끝난 뒤에 사용하기 위함.

        cout << "argc = " << argc << '\n';

        for (i = 1; i < argc - 1; ++i){
            cout << "argv[" << i << "] = " << argv[i] << '\n'; // argv[i]는 char*
        }
        
        cout << "argv[" << i << "] = " << argv[i] << '\n'; // 마지막 인자를 출력. 단, 공백은 제외
    }

    return 0;
}