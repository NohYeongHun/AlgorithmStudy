#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int board[10002];
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    fill(board, board + 10000 , 0);

    for (int i = 0; i != N; ++i) {
        int tmp;
        cin >> tmp;
        board[tmp]++;
    }

    for (int i = 1; i != 10001; ++i) {
        while (board[i] != 0) {
            cout << i << '\n';
            board[i]--;
        }
    }


}