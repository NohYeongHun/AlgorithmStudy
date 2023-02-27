#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int MX = 2000005;
int q[MX];
int n;

int head, tail = 0;

void push(int v){
    q[tail++] = v;
    tail %= MX;
}

int qEmpty(){
    if(head == tail) return 1;
    else return 0;
}

int pop(){
    if (head == tail) return -1;
    int temp = q[head];
    head = (head + 1) % MX;
    return temp;
}

int front(){
    if (qEmpty()) return -1;
    return q[head];
}

int back(){
    if (qEmpty()) return -1;
    return q[(tail - 1 + MX) % MX];
}

int size(){
    return tail - head;
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string op;
    int v;
    for(int i = 1; i < n+1; i++){
        push(i);
    }
    int f, b;
    while(size() > 1){
        pop();
        f = front();
        push(f);
        pop();
    }
    cout<< front();

    return 0;
}