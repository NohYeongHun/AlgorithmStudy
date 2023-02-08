#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int temp;
    int n1, n2;
    char result[3];

    for(int i = 0; i < 3; i++){
        n1 = 0, n2 = 0;
        for (int j = 0; j < 4; j++){
        cin >> temp;
        if (temp == 0) n1 += 1;
        else n2 += 1;
    } 

        if (n1 == 1) result[i] = 'A';
        else if (n1 == 2) result[i] = 'B';
        else if (n1 == 3) result[i] = 'C';
        else if (n1 == 4) result[i] = 'D';
        else result[i] = 'E';
    }

    for (char val : result){
        cout << val << "\n";
    }
    

}