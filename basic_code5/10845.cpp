#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int MX = 1000005;
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



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string op;
    int v;
    while(n--){
        cin >> op;
        if (op == "push"){
            cin >> v;
            push(v);
        }
        else if(op == "front"){
            cout << front() << "\n";
        }
        else if(op == "back"){
            cout << back() << "\n";
        }
        else if(op == "size"){
            cout << tail - head << "\n";
        }
        else if(op =="empty"){
            cout << qEmpty() << "\n";
        }
        else if(op =="pop"){
            cout << pop() << "\n";
        }

    }

    return 0;
}