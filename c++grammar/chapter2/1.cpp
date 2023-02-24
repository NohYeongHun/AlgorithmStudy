#include <iostream>
#include <string>

using namespace std;
int main()

/*
    문제
    앞의 test문제에서 Hello, +{name}을 테두리에 떨어지지 않은 상태로 출력
    1. 빈칸 한칸을 없앤다.
    2. cols의 크기를 2 줄인다.
    3. 원하는 결과 출력
*/
{
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    const std::string greeting = "Hello, " + name + "!";
    const int pad = 1;
    const int rows = pad * 2 + 3;
    const std::string::size_type cols = greeting.size() + pad * 2;
    std::cout << std::endl;
    int r = 0;

    const std::string stars (cols, '*');
    

    for(int r = 0; r != rows; r++){

        std::string::size_type c = 0;

        while(c != cols){
            
            // 행과 열이 조건에 맞는 상황일 때.
            if(r == pad + 1 && c == pad){
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