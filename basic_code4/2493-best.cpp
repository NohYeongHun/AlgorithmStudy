#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
stack<pair<int,int>> tower;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;  
  // 가장 큰높이를 0번에 배정.
  tower.push({100000001, 0});
  for (int i = 1; i <= N; i++) {
    int height;
    cin >> height;
    // top에 해당하는 높이가 현재 입력받은 높이보다 적은 경우에 pop()
    while (tower.top().X < height)
      tower.pop();
    // 현재 top의 인덱스를 출력.    
    cout << tower.top().Y << " ";
    tower.push({height, i});      
  }
}