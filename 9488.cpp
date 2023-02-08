#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int exam;
    cin >> exam;

    if (exam >= 90){
        cout << "A";
    } else if (exam >=80){
        cout << "B";
    } else if (exam >=70){
        cout << "C";
    } else if (exam >= 60){
        cout << "D";
    } else{
        cout << "F";
    }

    return 0;

}