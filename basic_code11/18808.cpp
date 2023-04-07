#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int board[50][50];
int paper[12][12];
int N; int M; int K;
int r; int c;


void rotate(){
    int tmp[12][12];

    for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
        tmp[i][j] = paper[i][j];
  
    for(int i = 0; i < c; i++)
    for(int j = 0; j < r; j++)
        paper[i][j] = tmp[r-1-j][i];

    swap(r, c);
}

bool pasteCheck(int x, int y) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (board[x + i][y + j] == 1 && paper[i][j] == 1)
                return false;
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (paper[i][j] == 1)
                board[x + i][y + j] = 1;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    while (K--) {
        cin >> r >> c;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> paper[i][j];
            }
        }

        for (int ro = 0; ro < 4; ++ro) {
            bool isPaste = false; 
            for (int x = 0; x <= N - r; x++) {
                if (isPaste) break;
                for (int y = 0; y <= M - c; y++) {
                    if (pasteCheck(x, y)) {
                        isPaste = true;
                        break;
                    }
                }
            }
            if (isPaste) break;
            rotate();
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
        cnt += board[i][j];

    cout << cnt;
}