#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char board[12][6];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int visited[12][6];

    bool isEnd = false;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
            cin >> board[i][j];

    while (true)
    {
        char color;
        bool isDeleted = false;

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                color = board[i][j];
                if (color == '.')
                    continue;

                int visited[12][6];
                queue<pair<int, int> > q;
                queue<pair<int, int> > deleted;
                q.push({i, j});
                deleted.push({i, j});
                visited[i][j] = 1;
                int cnt = 1;
                int r; int c;
                while (!q.empty())
                {
                    tie(r, c) = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int dr = r + dx[dir];
                        int dc = c + dy[dir];

                        if (dr < 0 || dr >= 12 || dc < 0 || dc >= 6)
                            continue;
                        if (visited[dr][dc] == 1)
                            continue;
                        if (board[dr][dc] == color)
                        {
                            visited[dr][dc] = 1;
                            q.push({dr, dc});
                            deleted.push({dr, dc});
                            cnt++;
                        }
                    }
                }

                if (cnt >= 4)
                {
                    isDeleted = true;
                    // 삭제
                    while (!deleted.empty())
                    {
                        int r; int c;
                        tie(r, c) = deleted.front();
                        board[r][c] = '.'; 
                        deleted.pop();
                    }

                    // 아래로 떨어짐.
                    char cur;
                    for (int i = 10; i >= 0; i--)
                    {
                        for (int j = 0; j < 6; j++)
                        {
                            cur = board[i][j];
                            if (cur == '.')
                                continue;

                            int r; int c; int er; int ec;
                            r = i;
                            c = j;
                            er = r + 1;
                            ec = c;
                            
                            // 떨어질 수 있는 바닥인 동안.
                            while (er < 12 && board[er][c] == '.')
                            {
                                er++;
                            }
                            if (er == 12) er--;
                            // 삭제 후 이동
                            board[r][c] = '.';
                            board[er][ec] = cur;
                        }
                    }
                }
            }
        }

        if (isDeleted == false)
        {
            cout << ans;
            return 0;
        }
        else
        {
            ans++;
        }
        
        

        
    }
    
    
}