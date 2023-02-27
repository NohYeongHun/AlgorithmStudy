#include<iostream>
#include <iomanip>
#include <ios>
using namespace std;

streamsize getWidth(int number){

    streamsize numDigits;

    if(number < 0){
        numDigits = 2;
        number *= -1;
    }
    else numDigits = 1;

    while(number != 0)
    {
        ++numDigits;
        number /= 10;
    }

    return numDigits;

}

int main(){
    int startNumber, maxNumber;
    cout << "시작 값 = ";
    cin >> startNumber;

    cout << "종료 값 = ";
    cin >> maxNumber;

    streamsize startSetW = getWidth(startNumber * maxNumber);
    streamsize endSetW = getWidth(maxNumber * maxNumber);
    
    for(int i = startNumber; i < maxNumber; i++){  

        cout << "일반 값 = " << setw(startSetW) << i << "\n";
        cout << "제곱 값 = " << setw(endSetW) << i * i << "\n";
    }
}