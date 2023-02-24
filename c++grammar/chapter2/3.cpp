#include <iostream>
#include <string>

using namespace std;
/*
    문제
    앞의 문제에서 테두리와 인사말 사이의 공백의 양을 입력받아 결정.
*/
int main()
{
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    const std::string greeting = "Hello, " + name + "!";
    int pad;
    cout << "Please enter your pad: ";
    cin >> pad;
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