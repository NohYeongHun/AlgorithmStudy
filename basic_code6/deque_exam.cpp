#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX; int tail = MX;

int isEmpty(){
    if (head == tail) return 1;
    else return 0;
}

void push_front(int x){ 
    dat[--head] = x;
}

void push_back(int x){
    dat[++tail] = x;
}

void pop_front(){
    if(head != MX) head++;
}

void pop_back(){
    if(tail != MX) tail--;
}

int front(){
    // 앞이 비어있지 않다면.
    if(head != MX){
        return dat[head];
    }else{
        // 둘다 비어있으면
        if(tail == MX){
            return -1;
        }else{
            // 앞은 비어있는데 뒤는 안비어있다면?
            return dat[head + 1];
        }
    }
}

int back(){
    // 뒤가 비어있지 않다면.
    if(tail != MX){
        return dat[tail];
    }else{
        // 둘다 비어있으면
        if(head == MX){
            return -1;
        }else{
            // 뒤는 비어있는데 앞은 안비어있다면?
            return dat[tail - 1];
        }
    }
}

void test(){
    for(int i = 0; i!= 10; i++){
        if(i %2 == 0){
            push_front(i);
        }
        else{
            push_back(i);
        }
    }

    while(!isEmpty()){
        cout << "현재 front = " << front() <<"\n";
        cout << "현재 back = " << back() <<"\n";
        pop_front();
        pop_back();
    }

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    test();


    return 0;
}