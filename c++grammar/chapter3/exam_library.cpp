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
using std::vector;  using std::max;

int main(){

    vector<int> v;
    typedef vector<int>::size_type size;
    
    for(int i = 10; i != 0; i--){
        v.push_back(i);
    }

    vector<int>::iterator s = v.begin();
    vector<int>::iterator e = v.end();
    cout << "정렬 전" << "\n";
    for(int i = 0; i!= 10; i ++){
        cout << "v[" << i <<  "] = "<< v[i] << " "; 
    }
    cout << "\n";
    /*
        sort(s, e)
        범위 [s, e] 에 의해 정의되는 요소들을 재정렬 시킵니다.
        정렬 방법은 역순이 아닌 순서입니다.
    */ 
    sort(s, e);
    cout << "정렬 후" << "\n";
    for(int i = 0; i!= 10; i ++){
        cout << "v[" << i <<  "] = "<< v[i] << " "; 
    }

    /*
        max(e1, e2)
        e1 과 e2 표현식 중에 더 큰 것을 리턴
    */
    cout << "\n";
    cout << "1 과 10중 더 큰 값은? = " << max(1, 10);
    cout << "\n";

    int x;
    /*
        while (cin >> x)
        x에 적당한 타입의 값을 읽어들이고 스트림 상태 테스트,
        스트림이 에러 상태라면 테스트 실패, 그렇지 않으면 성공
        while문 본체 실행
    */
    while(cin >> x){
        cout << "x 출력 = " << x << " ctrl + d 누르거나 int 타입과 다른 타입의 값 입력시 종료 \n";
    }

    double t;
    t = 10.12345;
    /*
        t.precision(n)
        다음번 출력을 위해 스트림 t의 정밀도를 n으로 설정함.
        이전 정밀도 리턴

        c++ 에서 스트림은 cout에 쓰이거나 cin에서 읽는 데이터와 같이 프로그램 안팎으로 흐르는 데이터 흐름임.
        이 클래스의 경우 현제 네 가지 클래스에 관심이 있음

        istream은 범용 입력 스트림. cin은 istream의 예
        ostream은 범용 출력 스트림. cout 및 cerr은 모두 ostream의 예
        ifstream은 입력 파일 스트림. 데이터 파일에서 데이터를 읽는 특별한 종류의 istream
        ofstream은 출력 파일 스트림. 데이터 파일에서 데이터를 쓰는 특별한 종류의 ostream
    */    
    
    cout << "cout 기본 정밀도 = " << cout.precision() << "\n";
    cout << "정밀도 설정 전 t 값 = " << t << "\n";
    cout << "이전 정밀도 = " << cout.precision(2) << "\n";
    cout << "cout precision(2) t = " << t << "\n";
    
    /*
        setprecision(n)
        출력 스트림 s에 사용시 s.precision(n)과 동일한 효과를 나타냄.
        <iomanip>에 정의되어 있음.
    */
    cout << "setprecision(n) 적용 전 = " << t << "\nsetprecision(10) 적용 후 = " 
         << setprecision(10) << t << "\n";

    /*
        setprecision 및 
        precision에 의해 리턴되는 값의 타입을 나타냄. <ios>에 정의됨.
    */
    streamsize coutSize = cout.precision();
    cout << "cout stream size = " << coutSize << "\n";






}