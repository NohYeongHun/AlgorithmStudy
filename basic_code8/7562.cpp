#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second


int T, N;
int sr, sc, er, ec, r, c, dr, dc;
int dirs[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    
    while(T--){
        cin >> N;
        cin >> sr >> sc;
        cin >> er >> ec;


        queue<tuple<int, int, int> > Q;
        int cnt, ans;
        Q.push({0, sr, sc});
        int vis[302][302] = {0,};
        vis[sr][sc] = 1;

        while (!Q.empty()){
            tuple<int, int, int > cur = Q.front(); Q.pop();
            cnt = get<0>(cur);
            r = get<1>(cur);
            c = get<2>(cur);

            if(r == er && c == ec){
                ans = cnt; 
                break;
            } 

            for(int i = 0; i < 8; i++){
                dr = r + dirs[i][0];
                dc = c + dirs[i][1];

                if (dr < 0 || dr >= N || dc < 0 || dc >=N) continue;
                if (vis[dr][dc]) continue;
                Q.push({cnt + 1, dr, dc});
                vis[dr][dc] = 1;
            }
        }        
        cout << ans << '\n';
    }

}