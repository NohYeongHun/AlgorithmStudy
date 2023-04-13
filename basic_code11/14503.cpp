#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N; int M;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int board[51][51];
int cnt = 0;

// 해당 방향으로 갈 수 있는가?
bool isPossible(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) 
        return false; 
    if (board[r][c] == 1 || board[r][c] == -1)
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int x; int y; int dir;
    cin >> x >> y >> dir;

    for (int i = 0; i != N; ++i)
    for (int j = 0; j != M; ++j)
        cin >> board[i][j];
    
    queue<tuple<int, int, int> > q;
    q.push({x, y, dir});
    bool endFlag = false;
    while (!endFlag && !q.empty()) {
        int r; int c; int dir;
        tie(r, c, dir) = q.front(); q.pop();

        // 청소되어 있지 않다면? => 청소
        if (board[r][c] == 0)
            board[r][c] = -1;
        
        // 현재 칸의 주변 4칸 중 청소되지 않은 칸이 없다면?
        bool isClean = true;
        for (int d = 0; d != 4; ++d) {
            int dr; int dc;
            dr = r + dx[d];
            dc = c + dy[d];

            // 청소되지 않은 칸이 있는 경우.
            if (isPossible(dr, dc)) {   
                isClean = false;
                break;
            }
        }

        // 청소되지 않은 칸이 없다면? => 4칸중 갈 곳이 없다면?
        if (isClean) {
            // 뒤로 이동
            int curDir = (dir + 2) % 4;
            int nr; int nc;
            nr = r + dx[curDir];
            nc = c + dy[curDir];
             
            // 뒤로 갈수 없다면?
            if (board[nr][nc] == 1)
                endFlag = true;
            else
                q.push({nr, nc, dir});
        } 
        // 청소되지 않은 칸이 존재한다면?
        else {
            int curDir = dir;
            for (int d = 0; d != 4; ++d) {
                curDir = (curDir +3) % 4;
                int dr; int dc;
                dr = r + dx[curDir];
                dc = c + dy[curDir];
                // 갈 수 있다면?
                if (isPossible(dr, dc)) {
                    q.push({dr, dc, curDir});
                    break;
                }
            }
        }

    }

    int cnt = 0;
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != M; ++j) {
            if (board[i][j] == -1) 
                cnt++;
        }
    }
    
    cout << cnt;

    return 0;

}