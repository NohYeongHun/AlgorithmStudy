#include <iostream>
#include <string>

using namespace std;
int main()

/*
    문제
    인사말과 테두리를 구분하는 한 줄짜리 빈칸을 한 번에 한문자씩 출력함
    => 수정하여 한 번의 출력으로 모든 빈칸을 모두 출력하도록 만들기.
*/
{
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    const std::string greeting = "Hello, " + name + "!";
    int pad;
    cout << "Please enter your pad: ";
    cin >> pad;
    // frame에 필요한 총 행 계산
    const int rows = (pad * 2) + 3;
    // 총 필요한 열의 크기
    const std::string::size_type cols = greeting.size() + pad * 2 + 2;
    std::cout << std::endl;
    
    // greeting의 왼쪽 오른쪽 패딩 값.
    const string padStringLeftRight(pad, ' ');

    // greeting의 위 아래 위치한 패딩 값
    const string padStringTopBottom((cols - 2), ' ');    

    for(int r = 0; r != rows; r++){

        std::string::size_type c = 0;

        string line = "";
        while(c != cols){
            
            // 행과 열이 조건에 맞는 상황일 때.
            if(r == pad + 1 && c == pad + 1){
                line += greeting;
                c += greeting.size();
            } else {

                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1){
                    line += '*';
                    ++c;
                } else {
                    if (r == pad + 1)
                    {
                        // greeting의 padding
                        line += padStringLeftRight;
                        c += padStringLeftRight.size();
                    }

                    else{
                        
                        // greeting의 위 아래 padding
                        line += padStringTopBottom;
                        c += padStringTopBottom.size();
                    }
                }
        
            }
        }
        cout << line <<"\n";
    }

    return 0;
}