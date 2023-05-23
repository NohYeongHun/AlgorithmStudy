#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N;
int arr[1002];

void swap(int l, int r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}

void quick_sort(int left, int right)
{
    int pivot = arr[(left + right) / 2 ];
    int L = left;
    int R = right;
    
    do{

        while(arr[L] < pivot) {
            L++;
        }

        while(arr[R] > pivot) {
            R--;
        }

        if (L <= R) {
            swap(L, R);
            L++;
            R--;
        }
    }while(L <= R);

    if (left < R)
        quick_sort(left, R);
    if (L < right)
        quick_sort(L, right);


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i != N; ++i)
        cin >> arr[i];

    quick_sort(0, N - 1);

    for (int i = 0; i != N; ++i)
        cout << arr[i] << '\n';
}