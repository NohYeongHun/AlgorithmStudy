#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n1, n2, n3;

    int o1, o2, o3;

    cin >> n1 >> n2 >> n3;

    if(n1 > n2 && n1 > n3){
        if (n2 > n3) o1 = n1, o2 = n2, o3 = n3;
        if (n3 > n2) o1 = n1, o2 = n3, o3 = n2;
        
    } else if(n2 > n1 && n2 > n3){
        if (n1 > n3) o1 = n2, o2 = n1, o3 = n3;
        if (n3 > n1) o1 = n2, o2 = n3 ,o3 = n1;
    } else if(n3 > n1 && n3 > n2){
        if (n1 > n2) o1 = n3, o2 = n1, o3 = n2;
        if (n2 > n1) o1 = n3, o2 = n2, o3 = n1;
    }
    
    cout << o3 << " " << o2 << " " << o1;



    return 0;

}