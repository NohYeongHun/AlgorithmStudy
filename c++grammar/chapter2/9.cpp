#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b;

    cout << "첫번째 사용자 a : ";
    cin >> a;

    cout << "두번째 사용자 b : ";
    cin >> b;


    if (a > b) {
        cout << " a > b";
    } else if(a == b){
        cout << " a == b ";
    } else{
        cout << " a < b ";
    }

        

    
}