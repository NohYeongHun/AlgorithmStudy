#include <iostream>
#include <string>

using namespace std;

int main(){
    int startNumber = 10;
    int endNumber = -5;

    /*
        분석해보자
        10만 출력하려면 1개의 루프가 필요함. 10 - 10 + 1 = 1 즉 [0, 1)의 비대칭 범위 필요
        10과 9를 출력하려면 2개의 루프가 필요함. 10 - 9 + 1 = 2 즉 [0, 2)의 비대칭 범위 필요
        10, 9, 8을 출력하려면 3개의 루프가 필요함. 10 - 8 + 1 = 3 즉 [0, 3)의 비대칭 범위 필요

        시작번호 10
        종료번호 -5

        (10 - (-5)) + 1 = 16 즉 [0, 16]의 비대칭 범위 필요.
        NumLoops = ( (EndNumber - StartNumber) * flag) + 1
        위로세는 경우 flag = 1
        아니면 flag = -1
    */
   int numLoops = (startNumber - endNumber) + 1;

   // 실제 출력할 수
   int iOut;
   for(int i = 0, iOut = startNumber; i != numLoops; i++){
        cout << "Loop = " << i << "| i Out = " << iOut << endl;
        iOut--;
   }


}