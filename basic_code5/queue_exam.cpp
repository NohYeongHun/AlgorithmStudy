#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int MX = 5;
int q[MX];
int head, tail = 0;

void push(int v){
    q[tail++] = v;
    tail %= MX;
}

void pop(){
    head = (head + 1) % MX;
}

int front(){
    return q[head];
}

int back(){
    return q[(tail - 1 + MX) % MX];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < MX; i++){
        push(i);
        cout << "front = " << front() << "\n";
        cout << "back = " << back() << "\n";
    }
    cout << "\n";

    for (int i = 0; i < MX; i++){
        pop();
        cout << "front = " << front() << "\n";
        cout << "back = " << back() << "\n";
    }


    return 0;
}