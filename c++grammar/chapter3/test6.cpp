#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;   using std::setprecision;
using std::cout;   using std::string;
using std::endl;   using std::streamsize;
/*
    문제
    각 학생의 기말고사 성적이 최종 성저의 40%를 차지하고, 중간고사가 20%,
    과제 성적의 평균이 나머지 40%를 차지하는 수업이 있다고 합니다.
    학생들이 자신의 최종 성적을 계산하는데 도움을 줄 프로그램의 첫번째 버전.
*/
int main()
{
    // 학생의 이름을 묻고 읽어들임
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // 중간고사와 기말고사 성적을 묻고 읽어들임
    cout << "Please enter your midterm and final size exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // 과제성적을 요구함
    cout << "Enter all your homework grades, "
            "followed by endoffile: ";
    
    // 지금까지 읽은 성적의 개수와 합
    int count = 0;
    double sum = 0;

    // 과제 성적을 변수로 읽어들임
    double x;

    /* 
        불변식:
            지금까지 count 개의 성적을 읽었고,
            sum은 count개 성적의 합
        cin >> x 불변식은 
        >> 연산자가 왼쪽 피연산자를 리턴함.
        cin >> x 값의 요청은 
        cin >> x 를 실행한 뒤 cin의 값을 요청한다는 것과 동일함.
        불변식은 bool 값으로 변환되어야 충족 가능함.
        istream 클래스는 조건식에서 사용할 수 있는 값으로 cin을 변환할 수 있는 변환을 제공함.
        따라서 cin을 조건식으로 사용한다는 것은 cin으로부터 마지막 읽기 시도가 성공했는지를
        테스트하는 것과 동일하다는 것을 알 수 있다.

        읽기 시도가 실패하는 경우
        - 입력 파일의 끝까지 읽었을 경우
        - 읽으려는 변수의 타입과 호환되지 않는 입력이 들어왔을 경우, int로 읽으려 했는데
        숫자가 아닌 다른 값을 읽었을 때
        - 시스템이 입력 장치에 대한 하드웨어 오류를 감지했을 경우

    */
   
    // 과제 성적을 계속 입력받는다.
    while (cin >> x){
        // 과제의 개수를 센다.
        ++count;
        // 과제 점수의 총합을 구한다.
        sum += x;
    }

    if (count == 0)
    {
        cout << "\n 과제를 해오지 않았습니다. 해당 학생은 평가 받을 수 없습니다.";
        return 1;
    }

    // 결과물 출력
    streamsize prec = cout.precision();
    // 소수점 정밀도를 3으로 설정
    cout << "Your final grade is " << setprecision (3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         // 원래 값으로 정밀도를 리셋함.
         << setprecision(prec) << endl;

    return 0;
}