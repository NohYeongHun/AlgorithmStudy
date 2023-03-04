#include<iostream>
#include<string>
#include<map>

using std::string;
using std::map;
using std::cin;
using std::cout;;
using std::endl;

// map 연관 컨테이너 예시.
int main()
{
    string s;
    map<string, int> counters; // 각 단어와 그에 따른 카운터(counter) 저장

    // 입력을 받아들이고, 각 단어와 그 단어의 반복횟수를 저장.
    while(cin >> s){
        ++counters[s];
    }

    // 단어 및 그에 연관된 카운트(count) 출력
    for (map<string, int>::const_iterator it = counters.begin();
        it != counters.end(); ++it) {
            cout << it -> first << "\t" << it -> second << endl;
        }
        return 0;
}