#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v1;
    vector<double> v2; 

    string name;
    double score;

    // 학생 수
    int students;
    cout << "학생의 수 = ";
    cin >> students;

    // 과제 개수
    int homeworkCount;
    cout << "과제 개수 = ";
    cin >> homeworkCount;
    
    // 학생 이름 받기.
    for(int i = 0; i != students; i++){
        cout << "학생 이름 = ";
        cin >> name;
        v1.push_back(name);
    }

    // 학생들의 점수 생성 및 계산
    for(int i = 0; i!= students; i ++){
        int sum = 0;
        for(int count = 0; count!= homeworkCount; count++){
            cout << v1[i] <<" 학생의 " << count + 1 << "번쨰 성적 = " ;
            cin >> score; 
            sum += score;
        }
        score = sum / homeworkCount;
        v2.push_back(score);
    }

    int size = v1.size();
    for(int i = 0; i !=size; i++){
        cout << "학생 이름 = " << v1[i] << "| 학생 성적 = " << v2[i] << "\n";
    }




    return 0;
}