#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v;
    string word;
    string::size_type maxSize;
    string::size_type minSize;
    while(cin >> word){
        v.push_back(word);
        maxSize = max(maxSize, word.size());
        minSize = min(minSize, word.size());
    }

    cout << "가장 긴 string 길이 = " << maxSize << "\n";
    cout << "가장 짧은 string 길이 = " << minSize << "\n";    

    return 0;
}