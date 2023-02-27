#include <ios>
 
using std::streamsize;
 
// Original function for Solution to Exercise 4-3
// return the required streamsize to fit a particular integer number
streamsize getStreamWidth(int number)
{
 
    streamsize numDigits;
 
    // initialise numDigits and number depending on whether value is positive / negative.
    // If negative, require at least 2 spaces to fit the leading empty space string and the negative sign
    // If positive, require at least 1 space to fit the leading empty space string
    if (number < 0)
    {
        numDigits = 2;
        number *= -1;
    }
    else numDigits = 1;
 
    // numDigits is the number of divisions required to make number approaches zero (plus leading space and sign)
    // i.e. this is equivalent to the total stream width required
    while (number != 0)
    {
        ++numDigits;
        number /= 10;
    }
 
    return numDigits;
}
 
// overloaded function for Solution to Exercise 4-4
// return the required streamsize to fit a particular double number, given number of decimals
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