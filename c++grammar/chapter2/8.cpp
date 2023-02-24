#include <iostream>
#include <string>

using namespace std;

int main(){
    int num = 10;

    int idx = 0;
    int answer = 1;
    for(int idx = 1; idx < 10; idx++){
        answer *= idx;
    }
    cout << " 1 ~ 10 multiple : "<< answer;
}