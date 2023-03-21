#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int N;
char board[4000][8000];
void dfs(int r, int c, int size)
{
    // 왼쪽 시작 점
    int lr = r + size;
    int lc = c - size;

    // 오른쪽 시작 점.
    int rr = r + size;
    int rc = c + size;
    if (size == 3)
    {
        for (int i = r; i < lr; i++){
            for (int j = lc + 1; j < rc; j++){
                bool mask = (i % 3 == 0 && j == c) 
                            || (i % 3 == 1 && (j == c - 1 || j == c + 1) 
                            || (i % 3 == 2)); 
                if(mask){
                    board[i][j] = '*';
                }
            }
        }
        return;
    }
    int tempSize = size / 2;
    
    // 3개의 삼각형을 그리면 된다.
    dfs(r, c, tempSize);
    dfs(r + tempSize, c - tempSize, tempSize);
    dfs(r + tempSize, c + tempSize, tempSize);
   
    return;
}

int main()
{
    cin >> N;
    // 빈칸 채워넣기.
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N * 2; j++){
            board[i][j] = ' ';
        }
    }
    dfs(0, N - 1, N);
    

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N * 2; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }

}