#include<iostream>
#include<bits/stdc++.h>

using namespace std;
/*
    적록 색약 : 빨간색과 초록색을 같은 것으로 본다.
*/
#define X first
#define Y second

int n;
string board[102];
int visited[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c, dr, dc;
char word;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    queue<pair<int, int> > Q;
    int FirstCnt = 0; int SecondCnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 0){
                FirstCnt++;
                visited[i][j] = 1;
                char word = board[i][j];
                Q.push({i, j});
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    r = cur.X;
                    c = cur.Y;

                    for (int dir = 0; dir < 4; dir++){
                        dr = r + dx[dir];
                        dc = c + dy[dir];
                        if(dr < 0 || dr >= n || dc < 0 || dc >= n) continue;
                        if(visited[dr][dc]) continue;
                        if(board[dr][dc] == word){
                            Q.push({dr, dc});
                            visited[dr][dc] = 1;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        fill(visited[i], visited[i] + n, 0);
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'G'){
                board[i][j] = 'R';
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 0){
                SecondCnt++;
                visited[i][j] = 1;
                char word = board[i][j];
                Q.push({i, j});
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    r = cur.X;
                    c = cur.Y;

                    for (int dir = 0; dir < 4; dir++){
                        dr = r + dx[dir];
                        dc = c + dy[dir];
                        if(dr < 0 || dr >= n || dc < 0 || dc >= n) continue;
                        if(visited[dr][dc]) continue;
                        if(board[dr][dc] == word){
                            Q.push({dr, dc});
                            visited[dr][dc] = 1;
                        }
                    }
                }
            }
        }
    }
    cout << FirstCnt << " " << SecondCnt;
}