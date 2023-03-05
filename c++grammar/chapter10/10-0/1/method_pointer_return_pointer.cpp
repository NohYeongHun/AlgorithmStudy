#include<iostream>

using std::cout;
using std::endl;

int* get_ptr_to_int(int n)
{
    int* ptr = new int(n);
    return ptr;
}

int main(){
    int* ptr = get_ptr_to_int(42);
    cout << "Value of ptr: " << *ptr << endl; // Output: Value of ptr: 42
    cout << "Address of ptr: " << ptr << endl; // Address of ptr: 0x131606b60
    *ptr = 99;
    cout << "Value of ptr after modification: " << *ptr << endl; // Output: Value of ptr after modification: 99
    cout << "Address of ptr after modification: " << ptr << endl; // Address of ptr: 0x131606b60
    delete ptr;
}