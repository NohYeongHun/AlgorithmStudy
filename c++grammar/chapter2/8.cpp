#include <iostream>
#include <string>

using namespace std;

int main(){
    /*
        [startNum, endNum)에 해당하는 비대칭 범위 내의 모든 곱셈 값을 해결하는 프로그램.
    */

    int startNumber;
    cout << "startNumber : ";
    cin >> startNumber;

    int endNumber;
    cout << "endNumber : ";
    cin >> endNumber;

    int numElements = endNumber - startNumber;
    int numLoops = numElements - 1;

    int c;
    if (numElements == 0){
        c = 0;
    } else if (numElements == 1)
        { c = startNumber; }
    else
    {
        int a = startNumber;
        int b = startNumber + 1;

        cout << " i, a, b, c " << endl;
        for (int i = 0; i != numLoops; ++i){
            
            c = a * b;
            cout << i << ", " << a << ", " << b << ", " << c << endl;
            a = c;
            ++b;
        }    
    }
    cout << "Asymmetric range: [" << startNumber << "," << endNumber << ")" << endl;
    cout << "Number of elements: " << numElements << endl;
    cout << "Number of loops required: " << numLoops << endl;
    cout << "Product of numbers within the asymmetric range = " << c << endl;

}