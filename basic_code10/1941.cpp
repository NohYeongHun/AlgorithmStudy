#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
    'S' 이다솜파, 'Y' 임도연파
    접근 가능한 위치를 선정한다 => 25C7
    해당 접근 가능한 위치가 아니면 상하좌우 인접하더라도 무시한다.
    => q의 다음 값으로 push되지 않으므로 while 문 종료
*/
string board[5];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans = 0;
bool mask[25];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        cin >> board[i];

    // 칠공주 뽑기
    fill(mask + 7, mask+25, true);
    do{
        for (int i = 0; i < 25; i++)
        {
            cout << mask[i] << ' ';
        }
        cout <<'\n';
        queue<pair<int, int> > q;
        int S = 0; int cnt = 0;

        // 접근 가능한 위치, 이미 방문한 위치
        bool isPossible[5][5] = {}, isVisited[5][5] = {};
        for (int i = 0; i < 25; i++)
        {
            if (!mask[i])
            {
                int r = i / 5;
                int c = i % 5;
                isPossible[r][c] = true;

                if (q.empty()){
                    isVisited[r][c] = true;
                    q.push({r, c});
                }
            }
        }
        while(!q.empty())
        {
            int r, c;
            tie(r, c) = q.front();
            q.pop();
            cnt++;
            S += board[r][c] == 'S';
            for (int i = 0; i < 4; i++)
            {
                int dr = r + dx[i], dc = c + dy[i];
                if (dr < 0 || dr >= 5 || dc < 0 || dc >= 5 || !isPossible[dr][dc] || isVisited[dr][dc])
                    continue;
                q.push({dr, dc});
                isVisited[dr][dc] = true;
            }
        }   
        ans += (cnt >= 7 && S >= 4);

    } while(next_permutation(mask, mask + 25));

    cout << ans;
}