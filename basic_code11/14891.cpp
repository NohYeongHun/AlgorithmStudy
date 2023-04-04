#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string gear[5];
int K;
int number[101];
int direction[101];
/*
    N 극은 0 S극 1
    gear => 0번 부터
    톱니바퀴의 3번쨰 인덱스가 12시
    gear[idx][2]

    0 = > 4
    1 => 0, 4
    2 => 0, 4
    3 => 0

    회전한 톱니바퀴와 서로 맞닿은 톱니의 극이 다르다면, B는 A가 회전한 방향과 반대방향으로 회전
    반시계는 앞에가 빠짐
    반시계는 뒤에 0번 인덱스가 pop_front, push_back
    시계는 pop_back, push_front
*/

void rotate(int number, int dir)
{
    deque<char> q(gear[number - 1].begin(), gear[number - 1].end());

    // 반시계
    if (dir == -1)
    {  
        char start = q.front(); q.pop_front();
        q.push_back(start);
        string temp (q.begin(), q.end());
        gear[number - 1] = temp;
    }
    // 시계
    else if (dir == 1)
    {
        char end = q.back(); q.pop_back();
        q.push_front(end);
        string temp (q.begin(), q.end());
        gear[number - 1] = temp;
    }
}

int main()
{
    fill(number, number + 101, 0);
    fill(direction, direction + 101, 0);

    for (int i = 0; i < 4; ++i)
        cin >> gear[i];

    cin >> K;

    for (int i = 0; i < K; ++i)
    {
        cin >> number[i] >> direction[i];    
    }

    for (int i = 0; i <K; ++i)
    {
        int curNumber = number[i];
        int dir = direction[i];

        /*
            1. 회전할 Gear의 번호를 확인
            2. 회전하기전 Gear의 상태와, 방향 알기
            3. 회전 전 Gear와 연관된 톱니바퀴 찾기
            0 => 1[0]
            1 => 0[4], 2[0]
            2 => 1[4], 3[0]
            3 => 2[4]
            4. 만약 연관된 톱니바퀴의 맞닿은 부분이 서로 다른 극이면 연관된 톱니바퀴 회전.
            5. 회전된 톱니바퀴와 연관된 다른 부분도 확인 => 3번으로 돌아감.
            6. 연관된 톱니바퀴가 모두 회전
            7. 이제 회전하기로 했던 톱니바퀴 회전.

            
        */ 
        string temp = gear[curNumber - 1];

        if (curNumber == 1)
        {

        }

        // 회전
        rotate(gear[curNumber - 1], dir);

        if (curNumber == 1)
        {
            
        }


    }
    

}