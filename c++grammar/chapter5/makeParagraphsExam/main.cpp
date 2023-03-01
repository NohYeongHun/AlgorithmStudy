#include<iostream>
#include<vector>
#include<string>
#include"frame.h"
#include"vcat.h"
#include"hcat.h"
using std::vector;
using std::cout;    using std::cin; 
using std::string;  using std::getline;

vector<string> v, copyV, vertical, horizontal;
string s;
int main(){

    while(getline(cin, s)){
        v.push_back(s);
    }

    cout << "---------------------일반 출력 ----------------------------------- " << "\n";
    for(vector<string>::iterator iter = v.begin(); iter != v.end(); iter++){
        cout << *iter << "\n";
    }


    copyV = frame(v);
    cout << "---------------------frame 출력 ----------------------------------- " << "\n";
    for(vector<string>::iterator iter = copyV.begin(); iter != copyV.end(); iter++){
        cout << *iter << "\n";
    }

    vertical = vcat(v, copyV);
    cout << "---------------------수직 결합 ----------------------------------- " << "\n";
    for(vector<string>::iterator iter = vertical.begin(); iter != vertical.end(); iter++){
        cout << *iter << "\n";
    }

    horizontal = hcat(v, copyV);
    cout << "---------------------수평 결합 ----------------------------------- " << "\n";
    for(vector<string>::iterator iter = horizontal.begin(); iter != horizontal.end(); iter++){
        cout << *iter << "\n";
    }
    
}