#include<iostream>
#include<ios>
#include<iomanip>
#include<vector>
#include<algorithm>

using namespace std;
/*
    입력 스트림으로부터 단어들을 입력받아 vector에 저장하는 함수 작성.
    해당 함수를 사용하여 입력 단어의 개수와 각 단어들이 총 몇번 나왔는지 확인.
*/


istream& inputWords(istream& in, vector<string>& words){
    
    if(in){
        words.clear();
        
        string word;
        while(in >> word){
            words.push_back(word);
        }
    }

    return in;
}

vector<string>::size_type wordsCount(vector<string> vec){
    return vec.size();
}
int main(){

    
    vector<string> vecStr;
    inputWords(cin, vecStr);

    vector<string>::size_type countWords = wordsCount(vecStr);
    cout << "단어의 총 개수 = " << countWords << "\n";
    sort(vecStr.begin(), vecStr.end());
    string cur = *vecStr.begin();
    int count = 0;
    for(vector<string>::iterator iter = vecStr.begin(); iter <= vecStr.end(); iter++){
        string comp = *iter;
        if(cur == comp){
            count++;
        }else{
            cout << "현재 단어 = " << cur << "| 개수 = " << count << "\n";
            count = 1;
            cur = comp;
            
        }
    }

}