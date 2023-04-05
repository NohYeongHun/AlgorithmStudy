#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string gear[5];
int K;
int number[101];
int direction[101];


void rotate(int number, int dir)
{
    deque<char> q(gear[number - 1].begin(), gear[number - 1].end());

    // 반시계
    if (dir == -1)
    {
        char start = *(q.begin()); q.pop_front();
        q.push_back(start);
        string temp(q.begin(), q.end());
        gear[number - 1] = temp;
    }
    // 시계
    else if (dir == 1)
    {
        char end = *(q.end() -1); q.pop_back();
        q.push_front(end);
        string temp(q.begin(), q.end());
        gear[number - 1] = temp;
    }
}

// curNumber와 compNumber의 톱니바퀴를 비교하여 극이 같으면 false, 다르면 true => 회전
bool rotationCheck(int curNumber, int compNumber, int curIdx, int compIdx)
{

    char curMagnet = gear[curNumber - 1][curIdx];
    char compMagnet = gear[compNumber - 1][compIdx];

    if (curMagnet != compMagnet)
        return true;

    return false;
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

    for (int i = 0; i < K; ++i)
    {
        int curNumber = number[i];
        int dir = direction[i];

        
        // 회전 톱니바퀴 번호와 톱니바퀴 방향 저장
        vector<pair<int, int> > savedRotate;
        savedRotate.push_back({curNumber, dir});

        // 회전 방향
        int rightDir = dir;
        int leftDir = dir;

        // 왼쪽 회전
        for (int i = curNumber; i > 1 && rotationCheck(i, i - 1, 6, 2) == true; --i)
        {
            leftDir = leftDir == 1 ? -1 : 1;
            savedRotate.push_back({i - 1, leftDir });
        }

        // 오른쪽 회전
        for (int i = curNumber; i < 4 && rotationCheck(i, i + 1, 2, 6) == true; ++i)
        {
            rightDir = rightDir == 1 ? -1 : 1;
            // 반대 회전방향을 넣어줘야함.
            savedRotate.push_back({ i + 1,  rightDir});
        }
          

        // 회전할 톱니바퀴 회전
        for (const pair<int, int>& p : savedRotate)
        {
            rotate(p.first, p.second);
        }
        
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (gear[i][0] == '1')
        {
            ans += pow(2, i);
        }
    }

    cout << ans;


}