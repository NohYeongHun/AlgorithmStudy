#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N; int M;
int board[10][10];
int temp[10][10];
bool visited[10][10];
bool visTemp[10][10];
vector<pair<int, int> > blank;
queue<pair<int, int> > virus;

int ans = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool isPossible(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M)
        return false;
    if (visTemp[r][c] == true)
        return false;
    if (temp[r][c] == 1 || temp[r][c] == 2) 
        return false;
    return true;  
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for (int i = 0; i != N; ++i) {
    for (int j = 0; j != M; ++j) {
        int temp;
        cin >> temp;
        board[i][j] = temp;
        if (temp == 0) {
            visited[i][j] = false;
            blank.push_back({i, j});
        }
        else if (temp == 1) {
            visited[i][j] = true;
        }
        else if (temp == 2) {
            virus.push({i, j});
            visited[i][j] = true;
        }
        
        
      }
    }

    int size = blank.size();
    vector<bool> check(size - 3, false);
    check.insert(check.end(), 3, true);
    do {
        // 복사하기
        for (int i = 0; i != N; ++i) {
        for (int j = 0; j != M; ++j) {
            temp[i][j] = board[i][j]; 
            visTemp[i][j] = visited[i][j];
          }   
        }

        // 벽 세우기
        for (int i = 0; i != check.size(); ++i) {
            if (check[i] == true) {
                temp[blank[i].first][blank[i].second] = 1;
            }
        }
        // 바이러스 전파
        queue<pair<int, int> > virusTemp(virus);
        
        int r; int c;
        while (!virusTemp.empty()) {
            tie(r, c) = virusTemp.front(); virusTemp.pop();
            for (int d = 0; d != 4; ++d) {
                int dr = r + dx[d];
                int dc = c + dy[d];
                if (isPossible(dr, dc)) {
                    virusTemp.push({dr,dc});
                    temp[dr][dc] = 2;
                    visTemp[dr][dc] = true;
                }
            }
        }

        int cnt = 0;
        // 남은 안전공간 개수 세기
        for (int i = 0; i != N; ++i) {
            for (int j = 0; j != M; ++j) {
                if (temp[i][j] == 0) cnt++;
            }
        }
        
        ans = max(ans, cnt);
    } while (next_permutation(check.begin(), check.end()));
    
    cout << ans;

}