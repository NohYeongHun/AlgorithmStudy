#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int M;
int arr[10];
int visited[10];
// 값을 넣을 배열
int temp[10];

void dfs(int cnt, int s)
{  
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << temp[i] << " ";
        }
        cout << '\n';
        return;
    }

    // 중복 확인 임시변수
    int tmp = 0;
    for (int i = s; i < N; i++)
    {
        if (visited[i] == 0 && tmp != arr[i])
        {
            visited[i] = 1;
            temp[cnt] = arr[i];
            tmp = temp[cnt];
            dfs(cnt + 1, i);
            visited[i] = 0;
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    dfs(0, 0);

}