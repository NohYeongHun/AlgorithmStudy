#include<iostream>
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m;
int cnt, max_cnt, paint_cnt;
int board[502][502];
int vis[502][502];
int dr, dc, r, c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > Q;

int bfs(int r, int c){
    cnt = 0;
    Q.push({r, c});
    vis[r][c] = 1;
    while(!Q.empty()){
        cnt++;
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            dr = cur.X + dx[i];
            dc = cur.Y + dy[i];
            if(dr < 0 || dr >= n || dc < 0 || dc >=m) continue;
            if (vis[dr][dc] || board[dr][dc] != 1) continue;
            vis[dr][dc] = 1;
            Q.push({dr, dc});
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;  


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    max_cnt = 0;
    paint_cnt = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            paint_cnt++;    
            max_cnt = max(bfs(i, j), max_cnt);
        }
    }
    
    cout << paint_cnt << '\n' <<  max_cnt;
    

}