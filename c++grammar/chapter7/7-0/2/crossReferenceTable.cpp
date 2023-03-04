#include"xref.h"
#include"split.h"

using std::map;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main(){

    // 디폴트로 split 사용한 xref 호출
    map<string, vector<int> > ret = xref(cin);

    // 결과 출력
    for (map<string, vector<int> >::const_iterator it = ret.begin();
        it != ret.end(); it++) {

            // 단어 출력
            cout << it -> first << "\t" << " occurs on line(s) : ";

            // 하나 이상의 라인 번호를 출력
            vector<int>::const_iterator line_it = it ->second.begin();
            cout << *line_it; // 첫 번째 라인 번호 출력

            ++line_it;

            // 나머지 라인 번호를 출력(있다면)
            /*
                1라인에서 2번 사용시 1, 1 <= 이런식으로 표기됨.
            */
            while (line_it != it->second.end()) {
                cout << ", " << *line_it;
                ++line_it;
            }
            // 각 단어를 구별하기 위해 개행 문자 출력
            cout << endl;
        }
    
    return 0;

}