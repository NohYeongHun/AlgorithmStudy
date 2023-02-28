#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int checkFront;
bool errorCheck;
deque<int> dq;
string order, arrayIn, stringBuffer, temp;
int T, n;
string::size_type orderSize;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    checkFront = 1;
    cin >> T;
    while(T--){
        cin >> order;
        cin >> n;
        orderSize = order.size();
        cin >> arrayIn;
        
        arrayIn.erase(arrayIn.begin());
        arrayIn.erase(arrayIn.end() - 1);
        istringstream iss(arrayIn);
        while(getline(iss, stringBuffer, ',')){
            dq.push_back(stoi(stringBuffer));
        }

        for(string::size_type i = 0; i!= orderSize; i++){
            if (order[i] == 'R'){
                checkFront = (checkFront + 1) % 2;
            } else if(order[i] == 'D'){
                if (dq.empty()) {
                    errorCheck = true;
                    break;
                } else if (checkFront){
                    dq.pop_front();
                } else {
                    dq.pop_back();
                }
            }
        }

        if(errorCheck){
            cout << "error" << "\n";
        } else {
            stringstream ans;
            if (checkFront){
                while(!dq.empty()){
                    ans << dq.front() << ",";
                    dq.pop_front();
                }
                cout << "[" << ans.str().substr(0, ans.str().size() - 1) << "]" << "\n";
            } else {
                while(!dq.empty()){
                    ans << dq.back() << ",";
                    dq.pop_back();
                }
                cout << "[" << ans.str().substr(0, ans.str().size() - 1) << "]" << "\n";
            }
        }

        dq.clear();
        checkFront = 1;
        errorCheck = false;
    }
    return 0;
}