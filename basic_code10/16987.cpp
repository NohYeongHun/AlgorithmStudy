#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N;
int S[10]; int W[10];
int broken[10];
int ans = 0;
int cnt = 0;

void dfs(int k)
{
    if (k == N)
    {
        ans = max(ans, cnt);
        return;
    }
    if(S[k] <= 0 || cnt == N-1){
        dfs(k+1);
        return;
    } 
    for (int i = 0; i < N; i++)
    {
        if (i == k || S[i] <= 0) continue;
        S[k] -= W[i];
        S[i] -= W[k];
        if (S[k] <= 0) cnt++;
        if (S[i] <= 0) cnt++;
        dfs(k + 1);
        if (S[k] <= 0) cnt--;
        if (S[i] <= 0) cnt--;
        S[k] += W[i];
        S[i] += W[k];
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
        cin >> W[i];
    }

    dfs(0);
    cout << ans;
}