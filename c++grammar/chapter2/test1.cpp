#include <iostream>
#include <string>

using namespace std;
int main()
{
    std::cout << "Please enter your first name: ";
    // read the name
    std::string name;
    std::cin >> name;
    const std::string greeting = "Hello, " + name + "!";
    // we have to rewrite this part...

    // the number of blanks surrounding the greeting
    const int pad = 1;
    // total number of rows to write
    const int rows = pad * 2 + 3;
    const std::string::size_type cols = greeting.size() + pad * 2 + 2;
    // separate the output from the input
    std::cout << std::endl;
    // write rows rows of output
    int r = 0;

    const std::string stars (cols, '*');
    const std::string emp(greeting.size(), ' ');
    
    // invariant: we have written r rows so far
    for(int r = 0; r != rows; r++){

        std::string::size_type c = 0;

        while(c != cols){
            
            // 행과 열이 조건에 맞는 상황일 때.
            if(r == pad + 1 && c == pad + 1){
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