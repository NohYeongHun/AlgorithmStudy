#include <iostream>
#include <string>

using namespace std;

int main(){
    int num = 10;

    int idx = 0;
    for(int num = 10; num >= 0; num--){
        if (num % 5 == 0){
            idx++;
            cout << idx << ". " << num << endl;
        }
    }
}