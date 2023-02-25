#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
    3-2.
    입력으로 정수 값을 읽어들여 그 중에 사분위수를 구하여 출력
    몇 번씩 나타나는지를 계산하는 프로그램 작성
*/
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<double> v;

    double val;
    /* 
        ctrl + d 또는 다른 타입의 변수 입력시 종료
        만약 count가 4개 이하면 바로 종료. => 4개 값숫자가 안되므로.
    */

    while(cin >> val){
        v.push_back(val);
    }

    typedef vector<double>::size_type vecSize;
    vecSize N = v.size();
    if (N == 0)
    {
        cout << "숫자를 입력하지 않았습니다.";
        return 1;
    }

    else if (N == 1)
    {
        cout << "숫자가 한개밖에 없습니다.";
        return 0;
    }

    else{
        sort(v.begin(), v.end());
    }

    // q1, q2, q3 를 구하기 위한 Mod
    vecSize NMod4 = (N % 4);
    string datumDistr = "";
    double m, ml, mu;

    int q1, q2, q3;
    if (NMod4 == 0){
        q2 = N / 2;
        q1 = q2 / 2;
        q3 = q2 + q1;
    } else if(NMod4 == 1){
        q2 = N / 2;
        q1 = q2 / 2;
        q3 = q2 + q1 + 1;
    } else if(NMod4 == 2){
        q2 = N / 2;
        q1 = q2 / 2;
        q3 = q2 + q1;
    } else if(NMod4 == 3){
        q2 = N / 2;
        q1  = q2 / 2;
        q3 = q2 + q1 + 1;
    }
    m = v[q2];
    ml = v[q1];
    mu = v[q3];

    streamsize prec = cout.precision();
    cout << "Display the sorted (non-descending) vector below." << endl;
    cout << "Index: Number" << endl;
    for (vecSize i = 0; i !=  N; ++i)
    {
        cout << i << ": " << v[i] << endl;
    }
    cout << endl;
    cout << "Vector size: " << N << endl;
    cout << "Datum Distribution: " << datumDistr << endl;
    cout << setprecision(3) << endl
         << " Q1: " << ml << endl
         << " Q2: " << m << endl
         << " Q3: " << mu << endl
         << setprecision(prec);
    
    return 0;
}