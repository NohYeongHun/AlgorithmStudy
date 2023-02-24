#include <iostream>
#include <string>

using namespace std;
/*
    문제
    "*" 문자 연속으로 사용하여 정사각형 사각형 삼각형 만들기
*/
int main()
{
    int pad = 1;
    int rows;
    cout << "rows : ";
    cin >> rows;
    const string::size_type square_cols = rows;
    int r = 0;

    // 정사각형
    {
        for(int r = 0; r != rows; r++){

            string::size_type c = 0;

            while(c != square_cols){
                if (r == 0 || r == rows - 1 || c == 0 || c == square_cols - 1){
                    cout << "*";
                }else{
                    cout << " ";
                }
                ++c;
            }
            cout << "\n";
        }
    }
    cout << endl;

    {
        // 직사각형
        const string::size_type rectangle_cols = rows * 2;
        for(int r = 0; r!= rows; r++){
            string::size_type c = 0;

            while(c != rectangle_cols){
                if (r == 0 || r == rows - 1 || c == 0 || c == rectangle_cols - 1){
                    cout << "*";
                }else{
                    cout << " ";
                }
                ++c;
            }
            cout << "\n";

        }
    }
    cout << endl;

    {
        // 삼각형
        const string::size_type cols = rows * 2;
        int count;
        for(int r = 0; r!= rows; r++){
            string::size_type c = 0;
            count = rows - (r + 1);

            while(c != cols){
                if (c < count || c > cols - count - 1){
                    cout << " ";
                } else{
                    cout << "*";
                }
                ++c;
            }
            cout << "\n";
        }
    }


    return 0;
}