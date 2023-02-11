#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int MX = 10000;
int dat[MX], pre[MX], nxt[MX];
int unused = 6;


void traverse(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert(int addr, int num){
    int next = nxt[addr];

    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = next;

    if(next != -1) pre[next] = unused;

    // 연결 변경.
    nxt[addr] = unused;

    unused ++;
}

void erase(int addr){
    int prev = pre[addr];
    int next = nxt[addr];
    // 앞에 같이 존재한다면?
    if(next != -1) pre[next] = prev;
    // prev의 next 값은 next이다.
    nxt[prev] = next;
    // next의 prev 값음 prev이다.
    pre[next] = prev;
}

void insert_test(){
    traverse();
    insert(5, 10);
    insert(6, 15);
    traverse();
}

void erase

int main(void){
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    fill(dat, dat+MX, -1);

    nxt[0] = 2, nxt[1] = 4, nxt[2] = 1, nxt[4] = 5;
    dat[0] = -1, dat[1] = 65, dat[2] = 13, dat[4] = 21, dat[5] = 17;
    pre[5] = 4, pre[4] = 1, pre[1] = 2, pre[2] = 0;
    insert_test();
    
    erase(2);
    traverse();
    return 0;
}