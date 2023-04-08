#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// 북 동 남 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int board[21][21];
int temp[21][21];
int N;
int ans = 0;

bool isSum(int x, int y) {

    if (x != 0 && x == y) 
        return true;
    return false;
}

void move(int dir) {

    int dr = 0; int dc = 0;
    if (dir == 0) {
        int mov = dir;

        dir += 2;
        dir %= 4;
        for (int c = 0; c < N; ++c) {

            for (int k = 1; k < N; ++k) {
                dr = k + dx[mov];
                dc = c + dy[mov];
                if (temp[dr][dc] == 0) {
                    while(dr > -1 && temp[dr][dc] == 0) {
                        int nr = dr - dx[mov];
                        int nc = dc - dy[mov];
                        temp[dr][dc] = temp[nr][nc];
                        temp[nr][nc] = 0;

                        dr = dr + dx[mov];
                        dc = dc + dy[mov];
                    }
                }
            }

            
            for (int r = 0; r < N - 1; ++r) {
                dr = r + dx[dir];
                dc = c + dy[dir];

                int target = temp[r][c];
                int add = temp[dr][dc];
                
                if (isSum(target, add)) {
                    target += add;
                    temp[r][c] = target;

                    // 땡기기.
                    while (dr < N - 1) {
                        int nr = dr + dx[dir];
                        int nc = dc + dy[dir];
                        temp[dr][dc] = temp[nr][nc];
                        dr = nr;
                        dc = nc;
                    }
                    // 마지막 구간.
                    temp[dr][dc] = 0;
                }
            }
        }
    }
    else if (dir == 1) {
        int mov = dir;

        dir += 2;
        dir %= 4;
        for (int r = 0; r < N; ++r) {
            // 빈칸 이동
            for (int k = N - 2; k > -1; --k) {
                dr = r + dx[mov];
                dc = k + dy[mov];
                if (temp[dr][dc] == 0) {
                    while(dc < N && temp[dr][dc] == 0) {
                        int nr = dr - dx[mov];
                        int nc = dc - dy[mov];
                        temp[dr][dc] = temp[nr][nc];
                        temp[nr][nc] = 0;

                        dr = dr + dx[mov];
                        dc = dc + dy[mov];
                    }
                }
            }

            for (int c = N - 1; c > 0; --c) {
                dr = r + dx[dir];
                dc = c + dy[dir];

                int target = temp[r][c];
                int add = temp[dr][dc];
                
                if (isSum(target, add)) {
                    target += add;
                    temp[r][c] = target;

                    // 땡기기.
                    while (dc > 0) {
                        int nr = dr + dx[dir];
                        int nc = dc + dy[dir];
                        temp[dr][dc] = temp[nr][nc];
                        dr = nr;
                        dc = nc;
                    }
                    // 마지막 구간.
                    temp[dr][dc] = 0;
                }
            }
        }
    }
    else if (dir == 2) {
        int mov = dir;

        dir += 2;
        dir %= 4;
        for (int c = 0; c < N; ++c) {
            // 빈칸 이동
            for (int k = N - 2; k > -1; --k) {
                dr = k + dx[mov];
                dc = c + dy[mov];
                if (temp[dr][dc] == 0) {
                    while(dr < N && temp[dr][dc] == 0) {
                        int nr = dr - dx[mov];
                        int nc = dc - dy[mov];
                        temp[dr][dc] = temp[nr][nc];
                        temp[nr][nc] = 0;

                        dr = dr + dx[mov];
                        dc = dc + dy[mov];
                    }
                }
            }

            for (int r = N - 1; r > 0; --r) {
                dr = r + dx[dir];
                dc = c + dy[dir];

                int target = temp[r][c];
                int add = temp[dr][dc];
                
                if (isSum(target, add)) {
                    temp[r][c] += add;

                    // 땡기기.
                    while (dr > 0) {
                        int nr = dr + dx[dir];
                        int nc = dc + dy[dir];
                        temp[dr][dc] = temp[nr][nc];
                        dr = nr;
                        dc = nc;
                    }
                    // 마지막 구간.
                    temp[dr][dc] = 0;
                }
            }
        }
    }
    else if (dir == 3) {
        
        int mov = dir;
        dir += 2;
        dir %= 4;
        for (int r = 0; r < N; ++r) {

            // 빈칸 이동
            for (int k = 1; k < N; ++k) {
                dr = r + dx[mov];
                dc = k + dy[mov];
                int val = temp[r][k];
                if (temp[dr][dc] == 0) {
                    while(dc >=0 && temp[dr][dc] == 0) {
                        int nr = dr - dx[mov];
                        int nc = dc - dy[mov];
                        temp[dr][dc] = temp[nr][nc];
                        temp[nr][nc] = 0;

                        dr = dr + dx[mov];
                        dc = dc + dy[mov];
                    }
                }
            }


            for (int c = 0; c < N - 1; ++c) {
                dr = r + dx[dir];
                dc = c + dy[dir];

                int target = temp[r][c];
                int add = temp[dr][dc];
                
                if (isSum(target, add)) {
                    temp[r][c] += add;

                    /*
                        합쳐진 열이 아닌 다른 열도
                        이동이 가능하면 이동해야함.
                    */
                    while (dc < N - 1) {
                        int nr = dr + dx[dir];
                        int nc = dc + dy[dir];
                        temp[dr][dc] = temp[nr][nc];
                        dr = nr;
                        dc = nc;
                    }
                    // 마지막 구간.
                    temp[dr][dc] = 0;
                }
            }
        }
    }
}

void copy_board() {
    for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
        temp[i][j] = board[i][j];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
        cin >> board[i][j];
    

    // 경우의 수 4 ^ 5 개
    for (int tmp = 0; tmp < 1 << (2 * 5); ++tmp)
    {
        // temp를 처음 보드로 변경
        copy_board();
        // 4진수 방향
        int val = tmp;
        for (int num = 0; num < 5; ++num)
        {
            int dir = val % 4;
            val /= 4;
            move(dir);
        }

        for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ans = max(temp[i][j], ans);
    }

   

    cout << ans;

}