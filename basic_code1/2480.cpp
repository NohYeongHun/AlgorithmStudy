#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int max;

    if (n1 >= n2 & n1 >= n3) max = n1;
    else if(n2 >= n1 & n2 >= n3) max = n2;
    else if(n3 >= n1 & n3 >= n2) max = n3; 

    if(n1 == n2 && n2 == n3){
        cout << 10000 + n1 * 1000;
    } else if (n1 == n2 | n1 == n3 | n2 == n3){
        if (n1 == n2 | n1 == n3) cout << 1000 + n1 * 100;
        else cout << 1000 + n2 * 100;
    } else {
        cout << max * 100;
    }

    return 0;

}