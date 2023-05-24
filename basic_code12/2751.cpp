#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// mergeSort
int N;
int arr[1000002];
int tmp[1000002];

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int L = start, R = mid;

    // 27, 38, 3, 43
    for (int i = start; i != end; ++i)
    {
        if (R == end) tmp[i] = arr[L++];
        else if (L == mid) tmp[i] = arr[R++];
        else if (arr[L] <= arr[R]) tmp[i] = arr[L++];
        else tmp[i] = arr[R++];
    }

    for (int i = start; i != end; ++i)
        arr[i] = tmp[i];
}

void mergeSort(int start, int end)
{
    if (end - start == 1) return;
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
        cin >> arr[i];
    
    mergeSort(0, N);
    for (int i = 0; i != N; ++i)
        cout << arr[i] << '\n';


}