#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string arrayIn = "[1, 2, 3, 4]";
    arrayIn = arrayIn.substr(1, arrayIn.size() - 2);
    istringstream iss(arrayIn);
    string stringBuffer;

    
    while(getline(iss, stringBuffer, ',')){
        cout << stringBuffer << " ";
    }
    cout << "\n";
    cout << arrayIn;


    stringstream ans;
    
    deque<int> dq;
    for(int i = 1; i != 5; i++){
        dq.push_back(i);
    }

    
    while(!dq.empty()){
        ans << dq.front() << ", ";
        dq.pop_front();
    }
    cout << "\n";
    cout << ans.str().substr(ans.str().size() - 1) << "\n";
    return 0;
}