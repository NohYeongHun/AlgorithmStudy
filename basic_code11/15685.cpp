#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N;
int board[200][200];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i != N; ++i) {
        int r, c, d, g;
        cin >> c >> r >> d >> g;
        
        vector<int> v;
        v.push_back(d);
        board[r][c] = 1;

        while(g--) {
            int vSize = v.size();
            /*
                방향
                0
                0 1
                0 1 2 1
                0 1 2 1 2 3 2 1
                0 1 2 1 2 3 2 1 2 3 0 3 2 3 2 1
            */
            for (int j = vSize - 1; j > -1; --j) {
                v.push_back((v[j] + 1) %  4);
            }
        }

        for (int k = 0;  k != v.size(); ++k) {
            int dir = v[k];
            r += dx[dir];
            c += dy[dir];
            board[r][c] = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i != 100; ++i) {
        for (int j = 0; j != 100; ++j) {
            
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1]) cnt++;
        }
    }

    cout << cnt;


}