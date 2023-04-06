#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N; int M;
int board[10][10];
int temp[10][10];
vector<pair<int, int> > cctv;
int ans = 1e9;
bool visited[10];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int dirs[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int cameras[6][4][4] = {
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{1, 0, 0, 0}, {2, 0, 0, 0}, {3, 0, 0, 0}, {4, 0, 0, 0}},
    {{1, 2, 0, 0}, {3, 4, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{1, 3, 0, 0}, {1, 4, 0, 0}, {2, 3, 0, 0}, {2, 4, 0, 0}},
    {{1, 2, 3, 0}, {1, 2, 4, 0}, {1, 3, 4, 0}, {2, 3, 4, 0}},
    {{1, 2, 3, 4}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}
};

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
    fill(visited, visited + 10, false);

    // 세로, 가로
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp;
            cin >> temp;
            board[i][j] = temp;

            if (temp == 0 || temp == 6) continue;
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