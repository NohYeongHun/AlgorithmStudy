#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int board[200][200];
int N;

int cnt1, cnt2;
void dfs(int r, int c, int size){

    int val = board[r][c];
    if(size == 1){
        if(val == 0) cnt1++;
        else if(val == 1) cnt2++;
        return;
    }
    int er = r + size;
    int ec = c + size;
    for(int i = r; i < er; i++){
        for(int j = c; j <ec; j++){
            int temp_size = size / 2;
            if(board[i][j] != val){
                dfs(r, c, temp_size);
                dfs(r, c + temp_size, temp_size);
                dfs(r + temp_size, c, temp_size);
                dfs(r + temp_size, c + temp_size, temp_size);
                return;
            }
        }
    }

    if(val == 0) cnt1++;
    else if(val == 1) cnt2++;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    dfs(0, 0, N);
    cout << cnt1 << '\n' << cnt2 <<'\n';
}