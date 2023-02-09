#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int *calc(int time){
    static int ret[2];
    ret[0] = (time / 30) * 10 + 10;
    ret[1] = (time / 60) * 15 + 15;
    
    return ret;
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int phone[n];
    int pricesY = 0;
    int pricesM = 0;
    
    // 영식 Y, 민식 M
    for (int i = 0; i < n; i ++){
        cin >> phone[i];
        int *ptr = calc(phone[i]);
        pricesY += ptr[0];
        pricesM += ptr[1];
    }

    if (pricesY == pricesM) cout << "Y" << " " << "M" << " " << pricesY;
    else if(pricesY < pricesM) cout << "Y " << pricesY;
    else cout << "M " << pricesM; 


    return 0;
}
