#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> S;
  int cnt = 1;
  string ans;
  // n이 0이 될때까지 수행
  while (n--) {
    // target 값
    int t;
    cin >> t;

    // cnt가 타겟 값보다 작거나 같으면.
    while (cnt <= t) {
    // 해당 값을 하나 씩 추가한다.
      S.push(cnt++);
      ans += "+\n";
    }
    // 타겟 값을 꺼내야 하는 차례에 타겟 값이 아니라면 => NO 출력
    if (S.top() != t) {
        // NO 출력후 실패.
      cout << "NO\n";
      return 0;
    }
    S.pop();
    ans += "-\n";
  }
  cout << ans;
}

/*
현재 처리를 필요로 하는 수는 cnt이다. cnt 이상인 값 t가 주어지면 그 값을 pop할 수 있게 cnt가 t가
될 때 까지 push를 해야 한다(18-21줄). 만약 22번째 줄과 같이 S.top()과 t가 일치하지 않는다면
올바르지 않은 수열이다.
*/