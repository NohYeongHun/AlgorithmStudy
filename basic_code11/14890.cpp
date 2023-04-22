#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N; int L;
int board[110][110];
int ans = 0;

bool check(vector<int>& line){
  int idx = 0;
  int cnt = 1;
  while (idx < N - 1) {
    if (abs(line[idx + 1] - line[idx]) > 1) return 0;
    if (line[idx] == line[idx + 1]) {
      cnt++;
      idx++;
    }
    else if (line[idx] < line[idx + 1]) {
      if (cnt < L) return 0;
      cnt = 1;
      idx++;
    }
    else {
      if (idx + L >= N) return 0;
      for (int i = idx + 1; i < idx + L; i++)
        if (line[i] != line[i + 1]) return 0;
      idx = idx + L;
      cnt = 0;
    }
  }
  return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != N; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i != N; ++i) {
        vector<int> line;
        for (int j = 0; j != N; ++j)  line.push_back(board[i][j]);
        ans += check(line);
    }

    for (int i = 0; i != N; ++i) {
        vector<int> line;
        for (int j = 0; j != N; ++j)  line.push_back(board[j][i]);
        ans += check(line);
    }

    cout << ans;
    


}