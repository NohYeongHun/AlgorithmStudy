#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N; int M;
int board[10][10];
int temp[10][10];
vector<pair<int, int> > cctv;
int ans = 1e9;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool out_line(int x, int y)
{
    return (x < 0 || x >= N || y < 0 || y >= M);
}

int blind_spot()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

void fill_board(int r, int c, int dir)
{
    dir %= 4;
    while(true) {
        r += dx[dir];
        c += dy[dir];
        if(out_line(r, c) || temp[r][c] == 6) break;
        if(temp[r][c] != 0) continue;
        temp[r][c] = -1;
   }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 세로, 가로
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;

            if (tmp == 0 || tmp == 6) continue;
            // r, c, cctv 종류
            cctv.push_back({i, j});
        }
    }

    if (cctv.size() == 0)
    {
        cout << 0;
        return 0;
    }

    // 총 경우의수 4 ^ 8개 => 2 ^ 16개
    for (int tmp = 0; tmp < 1 <<(2*cctv.size()); tmp++)
    {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                temp[i][j] = board[i][j];
        // 빈 보드에서 경우의 수를 끝까지 적용
        int val = tmp;
        for (int i = 0; i < cctv.size(); i++) {
            int dir = val % 4;
            val /= 4;
            int r = cctv[i].first;
            int c = cctv[i].second;

            if (board[r][c] == 1) {
                fill_board(r, c, dir);
            }
            else if (board[r][c] == 2) {
                fill_board(r, c, dir);
                fill_board(r, c, dir + 2);
            }
            else if (board[r][c] == 3) {
                fill_board(r, c, dir);
                fill_board(r, c, dir + 1);
            }
            else if (board[r][c] == 4) {
                fill_board(r, c, dir);
                fill_board(r, c, dir + 1);
                fill_board(r, c, dir + 2);
            }
            else {
                fill_board(r, c, dir);
                fill_board(r, c, dir + 1);
                fill_board(r, c, dir + 2);
                fill_board(r, c, dir + 3);
            }   
        }

        ans = min(ans, blind_spot());
    }

    cout << ans;

}