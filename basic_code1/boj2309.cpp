#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    int numbers[101] = {};
    int users[10];
    int result[10] = {};
    int minusValue = 0;
    for(int idx = 1; idx < 10; idx ++){
        cin >> users[idx];
        sum += users[idx];
    }

    minusValue = sum - 100;
    

    int l = 0, r = 0, temp = 0;
    for(int idx = 1; idx < 10; idx ++){
        temp = minusValue - users[idx];
        if (numbers[temp] != 0){
            l = idx;
            r = numbers[temp];
            break;
        }

        numbers[users[idx]] = idx;
    }
    
    int idx = 1;
    for(int i = 1; i < 10; i++){
        if (i != l && i != r) result[idx] = users[i], idx += 1;
    }
    
    for(int i = 1; i < 8; i++){
        for(int j = i + 1; j < 8; j++){
            if (result[i] > result[j]){
                temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    for(int i = 1; i < 8; i ++){
        cout << result[i] << "\n";
    }
    return 0;

}