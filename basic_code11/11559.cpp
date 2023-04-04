#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool isPuyo;
bool vis[12][6];
string board[12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;


void resetVis(){
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 6; ++j)
            vis[i][j] = false;
}

void game(int x, int y){
    bool doErase = false;

    vis[x][y] = true;
    char color = board[x][y];
    queue<pair<int, int> > q;
    vector<pair<int, int> > tmp;
    q.push({x, y}); tmp.push_back({x, y});

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue; 
            vis[nx][ny] = true;
            q.push({nx, ny}); tmp.push_back({nx, ny});
        }
    }

    if (tmp.size() >= 4)
    {
        isPuyo = true;
        for(auto cur : tmp)
            board[cur.first][cur.second] = '.';    
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 12; ++i)
        cin >> board[i];

    do{
        isPuyo = false; // 뿌요가 터졌는지 여부
        for(int i = 0; i < 6; ++i){
            // 필드의 빈 칸을 모두 뿌요 위로 올림
            for(int j = 10; j >= 0; --j){
                int tmp = j;
                // 빈 칸일 경우 위치 변경
                while(tmp < 11 && board[tmp+1][i] =='.'){
                    swap(board[tmp][i], board[tmp+1][i]);
                    ++tmp;
                }
            }
        }
    
    // 2-1. 게임을 시작한다. => board 순회
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (!vis[i][j] && board[i][j] != '.')
            {
                game(i, j);
            }
        }
    }

    if (isPuyo)
    {
        ++ans;
    }
    resetVis();
    } while(isPuyo);

    cout << ans;
}