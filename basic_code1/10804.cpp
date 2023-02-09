#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

void swap(int cards[], int l, int r){
    int temp = cards[l];
    cards[l] = cards[r];
    cards[r] = temp;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cards[21];
    int n, m;

    for (int i = 0; i < 21; i++) cards[i] = i;

    for (int i = 0; i < 10; i ++){
        cin >> n >> m;

        int temp = n;
        for(int k = m; k > temp; k--){
            swap(cards, k, temp);
            temp += 1;
        }
    }
    
    for(int i = 1; i < 21; i++) cout << cards[i] << " ";


    return 0;
}