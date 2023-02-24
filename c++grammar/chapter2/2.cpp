#include <iostream>
#include <string>

using namespace std;
int main()

/*
    문제
    앞의 test문제에서 Hello, +{name}을 위 아래 경계와 좌 우 경계에 사용되는 공백의 양을 달리하도록 프로그래밍
    1. rows 크기 3에서 5로 증가.
    2. 시작 행, r 을 5행으로 변경, c를 3열로 변경.
    3. 원하는 결과 출력
*/
{
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    const std::string greeting = "Hello, " + name + "!";
    const int pad = 2;
    const int rows = pad * 2 + 3;
    const std::string::size_type cols = greeting.size() + pad * 2 + 3;
    std::cout << std::endl;
    int r = 0;

    const std::string stars (cols, '*');
    

    for(int r = 0; r != rows; r++){

        std::string::size_type c = 0;

        while(c != cols){
            
            // 행과 열이 조건에 맞는 상황일 때.
            if(r == pad + 2 && c == pad){
                cout << greeting;
                c += greeting.size();
            } else {

                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1){
                    cout << "*";
                } else {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << "\n";
    }

    return 0;
}