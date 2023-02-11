#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int MX = 10000;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;


void traverse(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert(int addr, int num){
    int idx = -1;
    for(int i = 1; i < MX; i++){
        if (dat[i] == -1){
            idx = i; 
            break;
        } 
    }
    cout << "idx : " << idx << "\n";
    dat[idx] = num;
    int next = nxt[addr];
    int cur = addr;

    // 연결 변경.
    pre[next] = idx;
    nxt[idx] = next;
    pre[idx] = cur;
    nxt[cur] = idx;
}

void erase(int addr){
    dat[addr] = -1;
    int prev = pre[addr];
    int next = nxt[addr];
    nxt[prev] = next;
    pre[next] = prev;
}

int main(void){
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    fill(dat, dat+MX, -1);

    nxt[0] = 2, nxt[1] = 4, nxt[2] = 1, nxt[4] = 5;
    dat[0] = -1, dat[1] = 65, dat[2] = 13, dat[4] = 21, dat[5] = 17;
    pre[5] = 4, pre[4] = 1, pre[1] = 2, pre[2] = 0;

    traverse();
    insert(5, 10);
    traverse();
    erase(2);
    traverse();
    return 0;
}