#include<algorithm>
#include <vector>
#include <stdexcept>

using std::vector;
using std::domain_error;


/*
    template 함수는 타입에 대한 추론을 통해 실행되는 함수이다.
    풀어보자면 T 타입이 '컴파일 되는 시점'에 결정되고
    해당하는 T 타입이 함수에 적용된다고 보면 된다.
    그러나 여기에는 중요한 사실이 있다.
    어떤 타입이나 템플릿 함수에 적용가능한 것이 아니라는 것.
    함수에 맞는 적당한 타입이 템플릿 함수에 적용되는 것이라는 뜻이다.

    템플릿 설계하고 사용할 때 가장 어려운 부분은 바로 템플릿과 템플릿에
    사용될 '적당한 타입' 사이의 상호 관계를 아는 것이다.

    median 함수에 사용되는 타입은 +(더하기 연산), /(나누기 연산) 을 지원해야 한다.
    여기서 int나 double같은 산수형 타입의 경우에는 문제가 없지만
    string 타입은? => /(나누기 연산)을 지원하지 않는다.
    
*/
template<class T>
T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();

    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(v.begin(), v.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}