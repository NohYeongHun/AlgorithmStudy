#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N, L, R;
int ans = 0;
int board[100][100];
int temp[100][100];
bool visited[100][100];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool isPossible(int r, int c){
    if (r < 0 || r >= N || c < 0 || c >= N)
        return false;
    if (visited[r][c] == true)
        return false;
    return true;
}


void initVisited()
{
    for (int i = 0; i != N; ++i)
    for (int j = 0; j != N; ++j)
        visited[i][j] = false;
}

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;
    
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != N; ++j) {
            cin >> board[i][j];
            temp[i][j] = board[i][j];
            visited[i][j] = false;
        }
    }

    while(true) {
        initVisited();
        queue<pair<int, int >> q;
        for (int i = 0; i != N; ++i) {
            for (int j = 0; j != N; ++j) {
                if (visited[i][j] == true)
                    continue;
                    
                visited[i][j] = true;
                q.push({i, j});
                queue<pair<int, int>> tempQ;
                int tempSum = 0;
                while(!q.empty()) {
                    int r, c;                    
                    tie(r, c) = q.front(); q.pop();
                    int val = board[r][c];
                    tempQ.push({r, c});
                    tempSum += val;

                    for (int d = 0; d != 4; ++d) {
                        int dr = r + dx[d];
                        int dc = c + dy[d];
                        if (isPossible(dr, dc)) {
                            int dVal = board[dr][dc];
                            if (abs(dVal - val) >= L && abs(dVal - val) <= R) {
                                visited[dr][dc] = true;
                                q.push({dr, dc});
                            }
                        } 
                    }
                }
                int size = tempQ.size();
                int avg = tempSum / size;
                while(!tempQ.empty()) {
                    int r, c;
                    tie(r, c) = tempQ.front(); tempQ.pop();
                    temp[r][c] = avg;
                }
            }
        }

        bool flag = false;
        for (int i = 0; i!= N; ++i) {
            for (int j = 0; j!= N; ++j) {
                if (board[i][j] != temp[i][j]) {
                    flag = true;
                    ans++;
                }

                if (flag) break;
            }
            if (flag) break;
        }

        if (flag == false) {
            cout << ans;
            return 0;
        }
        else {
            for (int i = 0; i != N; ++i)
            for (int j = 0; j != N; ++j)
                board[i][j] = temp[i][j];
        }

    }
    
    


}