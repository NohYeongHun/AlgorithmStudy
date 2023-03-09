#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int board[102][102][102];
int dist[102][102][102];

// m : 열, n : 행, h : 높이
int m, n, h;
int r, c, e, dr, dc, de;
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main(){

    cin >> m >> n >> h;
    queue<tuple<int, int, int> > Q;
    // i : 높이, j : 행, k : 열
    for(int i = 0; i < h; i++){
    for(int j = 0; j < n; j++){
        for(int k = 0; k < m; k++){
            int temp;
            cin >> temp;
            board[i][j][k] = temp;
            if (temp == 1) Q.push({i, j, k});
            if (temp == 0) dist[i][j][k] = -1;
        }
      }
    }

    while(!Q.empty()){
        tuple<int, int, int> cur = Q.front(); Q.pop();
        // e : 높이, r : 행, c : 열
        e = get<0>(cur);
        r = get<1>(cur);
        c = get<2>(cur);

        for(int dir = 0; dir < 6; dir++){
            de = e + dz[dir];
            dr = r + dx[dir];
            dc = c + dy[dir];

            if(de < 0 || de >= h || dr < 0 || dr>= n || dc < 0 || dc >=m) continue;
            if(dist[de][dr][dc] >= 0) continue;
            Q.push({de, dr, dc});
            dist[de][dr][dc] = dist[e][r][c] + 1;
        }
    }

    int ans;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(dist[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                ans = max(dist[i][j][k], ans);
            }
        }
    }

    cout << ans;

}