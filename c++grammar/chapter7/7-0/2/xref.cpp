#include<map>
#include<iostream>
#include<vector>
#include<string>
#include "split.h"

using std::map;
using std::vector;
using std::string;
using std::istream;

/*
    입력 라인을 단어별로 쪼개고
    해당 단어들이 몇번 나타났는지를 알 수 있는 함수
    여기서 이해가 잘안갈 수 있는 부분.
    vector<string> find_words(const string&) = split
    
    vector<string> 타입의 find_words의 생성자에
    매개변수로 split함수가 적용된 string 참조값을 주겠다는 의미
    즉.
    1. string line => getline(cin, line) => 문장형태 스트링 받아옴.
    2. find_words(&line) <- find_words 생성자에 line 참조값을 매개변수로 넘김.
    3. 이때 split함수가 적용됨. find_words(split(&line)) 이 적용됨.
    4. split(const string& str)은 반환값이 vector<string>
    5. split함수의 반환값이 find_words 변수의 생성자의 매개변수로 적용
    6. find_words에는 split이 적용된 string vector 매개변수를 받아 생성됨.

*/
map<string, vector<int> >
    xref(istream& in,
        vector<string> find_words(const string&) = split)
        {
            string line;
            int line_number = 0;
            map<string, vector<int> > ret;

            // 다음 라인 읽어오기
            while (getline(in, line)) {
                ++line_number;

                // 입력 라인을 단어별로 쪼갬.
                vector<string> words = find_words(line);

                // 각 단어가 현재 라인에 나타났다는 사실을 기록합니다.
                for (vector<string>::const_iterator it = words.begin();
                    it != words.end(); ++it)
                    ret[*it].push_back(line_number);
            }

            return ret;
        }

