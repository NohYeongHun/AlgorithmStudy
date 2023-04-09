#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N; int M;
int board[51][51];
vector<pair<int, int> > chick;
vector<pair<int, int> > house;
int ans = 1e9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int cnt = 0;

    for (int i = 1; i < N + 1; ++i){
        for (int j = 1; j < N + 1; ++j) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if (tmp == 2) {
                chick.push_back({i, j});
                cnt++;
            }
            else if (tmp == 1) {
                house.push_back({i, j});
            }
        }
    }

    if (cnt == 0) {
        cout << 0;
        return 0;
    }

    vector<int> mask(chick.size(), 1);
    // 사용할 치킨집 뽑기
    fill(mask.begin(), mask.begin() + chick.size() - M, 0);
    do {
        int distSum = 0;
        for (int i = 0; i < house.size(); ++i) {
            int dist = 1e9;
            int r = house[i].first; int c = house[i].second;
            for (int idx = 0; idx < chick.size(); ++idx) {
                if (mask[idx] == 0) continue;
                int c_r = chick[idx].first; int c_c = chick[idx].second;
                int tmp;
                // 한 치킨집과의 거리
                tmp = abs(c_r - r) + abs(c_c - c);
                dist = min(tmp, dist);
            }
            distSum += dist;
        }
        
        ans = min(distSum, ans);
    } while (next_permutation(mask.begin(), mask.end()));

    cout << ans;

}