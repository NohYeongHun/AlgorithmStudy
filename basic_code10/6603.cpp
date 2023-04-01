#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int k;
int s;
int lotto[50];
int outArr[6];

void dfs(int cnt, int s)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; i++){
            cout << outArr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = s; i < k; i++)
    {
        outArr[cnt] = lotto[i]; 
        dfs(cnt + 1, i + 1); 
    }
}
int main()
{
    while(true)
    {
        cin >> k;
        if (k == 0) break;
        
        for (int i = 0; i < k; i++)
        {
            cin >> lotto[i];
        }

        sort(lotto, lotto + k);
        dfs(0, 0);

        cout << '\n';
    }
    
}