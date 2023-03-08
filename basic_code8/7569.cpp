#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int m, n, h, r, c, z, dr, dc, dh;
int board[102][102][102];
int dist[102][102][102];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int main(){
    cin >> m >> n >> h;
    queue<tuple<int, int, int> > Q;
    for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            int tmp;
            cin >> tmp;
            board[j][k][i] = tmp;
            if (tmp == 1) Q.push({j, k, i});
            if (tmp == 0) dist[j][k][i] = -1;
        }
    }
  }

  while(!Q.empty()){
    tuple<int, int, int> cur = Q.front(); Q.pop();
    r = get<0>(cur);
    c = get<1>(cur);
    z = get<2>(cur);
    for(int dir = 0; dir < 6; dir++){
        dr = r + dx[dir];
        dc = c + dy[dir];
        dh = z + dz[dir];
        if(dr < 0 || dr >= n || dc < 0 || dc >= m || dh < 0 || dh >= h) continue;
        if(dist[dr][dc][dh] >= 0) continue;    
        dist[dr][dc][dh] = dist[r][c][z] + 1;
        Q.push({dr, dc, dh});
    }
}
    int ans;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(dist[j][k][i] == -1){
                    cout << -1 << '\n';
                    return 0;
                }
                ans = max(ans, dist[j][k][i]);
            }

        }
    }

    cout << ans << '\n';
    return 0;

}