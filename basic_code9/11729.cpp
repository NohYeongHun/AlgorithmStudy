#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n;

void func(int a, int b, int n){
    // base condition
    if(n == 1){
        cout << a << " " << b << '\n';
        return;
    } 
    /*
        n - 1 개 원판을 기둥 a 에서 기둥 6 - a - b로 옮긴다.
        => n번째 원판이 b 번호의 기둥으로 가기 위해서 
        n번 원판을 기둥 a에서 기둥 b로 옮긴다.
        => n번 원판을 b번호로 옮긴다.
        n - 1 개의 원판을 기둥 6 - a - b에서 기둥 b로 옮긴다.
        => 옮겨진 원판을 b번 기둥으로 옮긴다.
    */
    func(a, 6 - a - b, n - 1);
    cout << a << " " << b << '\n';
    func(6 - a - b, b, n - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << (1 << n) - 1<< '\n';
    func(1, 3, n);
    


}