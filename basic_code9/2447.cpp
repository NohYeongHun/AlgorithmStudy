#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int N;
string stars1 = "***";
string stars2 = "* *";
char board[2200][2200];
void dfs(int r, int c, int size, bool isEmpty)
{
    int er = r + size;
    int ec = c + size;
    if (size == 3)
    {
        if (isEmpty)
        {
            for (int i = r; i < er; i++){
            for (int j = c; j < ec; j++){
                board[i][j] = ' ';
              }
            }
        }
        else
        {
            for (int i = r; i < er; i++){
            for (int j = c; j < ec; j++){
                if (i % 3 == 1 && j % 3 == 1)
                {
                    board[i][j] = ' ';
                }
                else
                {
                    board[i][j] = '*';
                }
              }
            }
        }
        return;
    }
    
    int temp = size / 3;
    // 1열
    dfs(r, c, temp, isEmpty);
    dfs(r + temp, c, temp, isEmpty);
    dfs(r + temp * 2, c, temp, isEmpty);

    // 2열
    dfs(r, c + temp, temp, isEmpty);
    dfs(r + temp, c + temp, temp, true);
    dfs(r + temp * 2, c + temp, temp, isEmpty);
    
    // 3열
    dfs(r, c + temp * 2, temp, isEmpty);
    dfs(r + temp, c + temp * 2, temp, isEmpty);
    dfs(r + temp * 2, c + temp * 2, temp, isEmpty);
    return;
}

int main()
{
    cin >> N;
    dfs(0, 0, N, false);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }

}