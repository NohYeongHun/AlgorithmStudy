#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
    3-1 연습문제 => 상당히 난해하다
    버리지 않은 전체 세트의 진정한 중앙 값은
    버린 동일한 전체 세트의 중앙값과 다를 수 있다.
    그러므로 숫자를 버릴 수 없다.
*/
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int size = 10;
    /* 
        값을 10개 정도 받아보자.
        1 2 3 4 5 6 7 8 9 10
    */
    for (int i = 0; i != size; i++){
        v.push_back(i + 1);
    }
    /*
        전체 세트의 중앙값을 구해보자.
    */
    int all_mid = size / 2;
    // 6 + 7 / 2
    int all_median = size % 2 == 0 ? (v[all_mid] + v[all_mid + 1]) / 2 : v[all_mid];
    
    cout << "전체 세트의 중앙 값 = " << all_median << "\n";

    /*
        몇개의 숫자를 버린 세트의 중앙 값.
    */
    v.pop_back();
    v.pop_back();
    size = v.size();
    
    cout << "현재 사이즈 = " << size << "\n";
    int part_mid = size / 2;
    int part_median = size % 2 == 0 ? (v[part_mid] + v[part_mid + 1]) / 2 : v[part_mid];
    cout << "부분 세트의 중앙 값 = " << part_median << "\n";

    


    return 0;
}