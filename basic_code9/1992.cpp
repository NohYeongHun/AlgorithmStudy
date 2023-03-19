#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N;
int board[100][100];
string str = "";

void dfs(int r, int c, int size){
    int val = board[r][c];
    if (size == 1)
    {
        str+= to_string(val);
        return;
    }

    int er = r + size;
    int ec = c + size;
    for (int i = r; i < er; i++){
        for (int j = c; j < ec; j++){
            if(val != board[i][j]){
                str += "(";
                int temp_size = size / 2;
                dfs(r, c, temp_size);
                dfs(r, c + temp_size, temp_size);
                dfs(r + temp_size, c, temp_size);
                dfs(r + temp_size, c + temp_size, temp_size);
                str += ")";
                return;
            }
        }
    }

    str += to_string(val);
    return;


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++){
            char tmp = temp[j];
            board[i][j] = tmp - '0';
        }
    }

    int val = board[0][0];
    bool isDfs = false;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (val != board[i][j]){
                isDfs = true;
                break;
            }
        }
        if (isDfs) break;
    }
    
    if(isDfs)
    {
        dfs(0, 0, N);
        cout << str << '\n';
    }
    else
    {
        cout << val << '\n';
    }

}