#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N;
int num[1000005];
int tmp[1000005];

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int L = start; int R = mid;

    // 43 38 27 3
    for (int i = start; i != end; ++i)
    {
        if (R == end) tmp[i] = num[L++];
        else if (L == mid) tmp[i] = num[R++];
        else if (num[L] >= num[R]) tmp[i] = num[L++];
        else tmp[i] = num[R++];
    }

    for (int i = start; i != end; ++i)
        num[i] = tmp[i];
}


void mergeSort(int start, int end)
{
    if (end - start == 1)
        return;
    int mid = (end + start) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    merge(start, end);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i != N; ++i)
        cin >> num[i];
    
    mergeSort(0, N);

    for (int i = 0; i != N; ++i)
        cout << num[i] << '\n';


}