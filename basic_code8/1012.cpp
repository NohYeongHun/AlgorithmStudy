#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int T, M, N, K;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int board[51][51];
int visited[51][51];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        int r, c;
        
        // 배추 배치.
        while(K--){
            cin >> c >> r;
            board[r][c] = 1;
        }

        queue<pair<int, int> > Q;
        int cnt = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(board[i][j] == 1 && visited[i][j] == 0){
                    Q.push({i, j});
                    visited[i][j] = 1;
                    while(!Q.empty()){
                        pair<int, int > cur = Q.front(); Q.pop();
                        int dr, dc;
                        for(int k = 0; k < 4; k++){
                            dr = cur.X + dx[k];
                            dc = cur.Y + dy[k];

                            if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
                            if (visited[dr][dc] == 1 || board[dr][dc] != 1) continue;
                            Q.push({dr, dc});
                            visited[dr][dc] = 1;
                            
                        }
                    }

                    cnt++;
                }
            }
        }
        for(int i = 0; i < N; i++){
            fill(board[i], board[i] + M ,0);
            fill(visited[i], visited[i] + M, 0);
        }
        cout << cnt << '\n';
    }

}