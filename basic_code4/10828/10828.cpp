#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int stacks[10001];
int result[10001];
int pointer = -1;
int resultP = 0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    fill(stacks, stacks + t, 0);
    string op;
    for(int i = 0; i < t; i++){
        cin >> op;
        int val;
        if(op == "push"){
            cin >> val;
            pointer++;
            stacks[pointer] = val;
        } else if (op == "top" ){
            if (pointer == -1) result[resultP++] = -1;
            else result[resultP++] = stacks[pointer];
        } else if (op == "size"){
            result[resultP++] = pointer + 1;
        } else if (op == "empty"){
            if (pointer == -1) result[resultP++] = 1;
            else result[resultP++] = 0;
        } else if (op == "pop"){
            if (pointer == -1) result[resultP++] = -1;
            else result[resultP++] = stacks[pointer--];
        }
    }

    copy(result, result + resultP,
            std::ostream_iterator<int>(std::cout, "\n"));
    

    return 0;
}