#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
    3-3. 입력으로 문장을 읽어들여 
    각각의 단어들이 몇개씩 나타나는지 개수 세기.
*/
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v;

    string word;
    // ctrl + d 또는 다른 타입의 변수 입력시 종료
    while(cin >> word){
        v.push_back(word);
    }

    typedef streamsize vecSize;
    vecSize N = v.size();
    vecSize numLoops = N - 1;
    vecSize ND;
    if (N == 0)
    {
        ND = 0;
        cout << "Number of distinct words = " << ND << "\n";
        return 0;
    }

    else if (N == 1)
    {
        ND = 1;
        cout << "Number of distinct words = " << ND << "\n";
        return 0;
    }

    else
    {
        sort(v.begin(), v.end());
        cout << "Vector size (number of words entered): " << N << endl;
        cout << endl;
        cout << "Display the sorted (non-descending) distinct words below." << endl;


        vecSize A = 0;     // vector index
        vecSize B = 1;     // vector index
        int count = 1;
        ND = 1;            // 서로 다른 단어 개수

        vector<string> result;
        vector<int> countVec;
        while(A != numLoops + 1){
            string cur = v[A];
            count = 1;
            for(vecSize i = A; i != numLoops; ++i){
                // 현재 값이 다음 값과 같다면?
                if(cur == v[i + 1]){
                    count++;
                } else {
                    // 현재 값이 다음 값과 다르다면?
                    break;
                }
                A++;
            }
            cout << "현재 단어 : " << cur << "| 개수 :" << count <<"\n";
            A++;
        }
        
    }



    return 0;
}