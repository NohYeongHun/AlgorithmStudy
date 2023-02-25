#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
// vector 컨테이너 import
#include <vector>
// sort 함수를 사용하기 위한 헤더 import
#include <algorithm>

using std::cin;   using std::setprecision;
using std::cout;   using std::string;
using std::endl;   using std::streamsize;
using std::vector;

int main(){

    vector<int> v;
    // 가장 큰 vector 에 들어가는 요소들의 최대 개수를 담을 수 있는 타입
    typedef vector<int>::size_type size;
    
    for(int i = 1; i != 11; i++){
        // vector에 i로 초기화된 요소 하나를 추가합니다.
        v.push_back(i);
    }

    // v.begin()은 v의 첫 번째 요소를 나타내며 vector의 iterator 타입의 값을 반환한다.
    vector<int>::iterator s = v.begin();
    // 값은 포인터로 참조해서 가져올 수 있다.
    cout << "첫 번째 값 = " << *s << "\n";

    // v.begin()은 v의 마지막 요소의 [한칸 지난 값]을 나타내며 vector의 iterator 타입의 값을 반환한다.
    vector<int>::iterator e = v.end();
    cout << "마지막 값 = " << *(e - 1) << "\n";
    cout << "마지막 한 칸 지난값 = " << *(e) << "\n";

    // v[i] 는 vector의 i번째 요소 값을 반환한다.
    cout << "v[i] = " << v[0] << "\n";

    // v.size()는 vector인 v에 들어있는 요소들의 개수를 리턴한다.
    size v_size = v.size();
    cout << "v.size() = " << v_size << "\n";



}