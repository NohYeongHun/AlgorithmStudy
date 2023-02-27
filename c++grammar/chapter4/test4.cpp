#include<iostream>
#include<ios>
#include<iomanip>
#include "getStreamWidth.h"
using namespace std;


streamsize getStreamWidth(double number, streamsize numDecimals)
{
    streamsize numDigits = numDecimals;
 
    // initialise numDigits and number depending on whether value is positive / negative.
    // If negative, require at least 2 spaces to fit the leading empty space string and the negative sign
    // If positive, require at least 1 space to fit the leading empty space string
    if (number < 0)
    {
        numDigits = 3 + numDecimals;  // (leading space + negative sign + decimal point) + decimals
        number *= -1;
    }
    else numDigits = 2 + numDecimals;  // (leading space + decimal point) + decimals
 
    // numDigits is the number of divisions required to make number approaches zero (plus leading space and sign)
    // i.e. this is equivalent to the total stream width required
    while (number >= 1)
    {
        ++numDigits;
        number /= 10;
    }
    return numDigits;
}
int main(){
    double m, n;
    const streamsize size = 3;  // number of decimal places
    cout << "시작 값 = ";
    cin >> m;

    cout << "종료 값 = ";
    cin >> n;

    streamsize front = max(getStreamWidth(m, size), getStreamWidth(n, size));
    streamsize back = max(getStreamWidth(m * m, size), getStreamWidth(n * n, size));

    cout << "m = " << setw(front) <<  m << "\n";
    cout << "n = " << setw(front) <<  n << "\n";

    cout << "m * m = " << setw(back) << m * m << "\n";
    cout << "n * n = " << setw(back) << n * n << "\n";
}