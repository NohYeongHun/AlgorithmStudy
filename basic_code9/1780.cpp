#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int board[2200][2200];

int cnt1, cnt2, cnt3;

void searchBoard(int r, int c, int t)
{
    bool isFlag = true;
    // 탈출 조건
    if (t == 1)
    {
        if (board[r][c] == -1)
            cnt1 += 1;
        else if (board[r][c] == 0)
            cnt2 += 1;
        else if (board[r][c] == 1)
            cnt3 += 1;
        return;
    }
    int er, ec;
    er = r + t;
    ec = c + t;

    // 시작 값
    int val = board[r][c];
    for (int i = r; i < er; i++)
    {
        for (int j = c; j < ec; j++)
        {
            if (val != board[i][j])
            {
                int tmp = t / 3;
                searchBoard(r, c, tmp);
                searchBoard(r, c + tmp, tmp);
                searchBoard(r, c + (tmp * 2), tmp);
                searchBoard(r + tmp, c, tmp);
                searchBoard(r + tmp, c + tmp, tmp);
                searchBoard(r + tmp, c + (tmp * 2), tmp);
                searchBoard(r + (tmp * 2), c, tmp);
                searchBoard(r + (tmp * 2), c + tmp, tmp);
                searchBoard(r + (tmp * 2), c + (tmp * 2), tmp);
                return;
            }
        }
    }
        
    if(val == -1) cnt1 += 1;
    if(val == 0) cnt2 += 1;
    if(val == 1) cnt3 += 1;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    cnt1 = 0;
    cnt2 = 0;
    cnt3 = 0;
    searchBoard(0, 0, N);
    cout << cnt1 << '\n'
         << cnt2 << '\n'
         << cnt3;
}