#include<iostream>
#include<bits/stdc++.h>

#define X first
#define Y second
using namespace std;

/*
    '.': 빈 공간
    '#': 벽
    '@': 상근이의 시작 위치
    '*': 불
*/

int T, w, h, r, c, dr, dc;
char board[1002][1002];
int distF[1002][1002];
int distH[1002][1002];

bool flag;
queue<pair<int, int> > humanQ;
queue<pair<int, int> > fireQ;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    

    while(T--){
        flag = false;
        cin >> w >> h;

        fireQ = queue<pair<int, int> >();
        humanQ = queue<pair<int, int> >();
        for(int i = 0; i < h; i++){
            fill(distF[i], distF[i] + w, 0);
            fill(distH[i], distH[i] + w, 0);
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                char c;
                cin >> c;
                board[i][j] = c;

                if(board[i][j] == '#'){
                    board[i][j] = -1;
                    continue;
                }
                else if(board[i][j] == '@'){
                    distH[i][j] = 1;
                    humanQ.push({i, j});
                }
                else if(board[i][j] == '*') {
                    distF[i][j] = 1;
                    fireQ.push({i, j});
                }

                board[i][j] = 0;
            }
            
        }

        while(!fireQ.empty()){
            pair<int, int> curF = fireQ.front(); fireQ.pop();
            r = curF.X;
            c = curF.Y;
            for(int dir = 0; dir < 4; dir++){
                dr = r + dx[dir];
                dc = c + dy[dir];

                if(dr < 0 || h <= dr || dc < 0 || w <= dc) continue;
                if(distF[dr][dc]) continue;
                if(board[dr][dc] == -1) continue;
                distF[dr][dc] = distF[r][c] + 1;
                fireQ.push({dr, dc});       

            }
        }

        while(!humanQ.empty() && !flag){
            pair<int, int> curH = humanQ.front(); humanQ.pop();
            r = curH.X;
            c = curH.Y;
            for(int dir = 0; dir < 4; dir++){                    
                dr = r + dx[dir];
                dc = c + dy[dir];
                if(dr < 0 || h <= dr || dc < 0 || w <= dc){
                    cout << distH[r][c] << '\n';
                    flag = true;
                    break;
                }
                if(board[dr][dc] == -1) continue;
                if(distH[dr][dc]) continue;
                if(distF[dr][dc] != 0 && distF[dr][dc] <= distH[r][c] + 1) continue;
                distH[dr][dc] = distH[r][c] + 1;
                humanQ.push({dr, dc});
                
            }
        }

        if(!flag){
            cout << "IMPOSSIBLE" << '\n';
        }
    }
}