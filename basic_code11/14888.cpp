#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int N;
int board[20];
int opMath[4];
int minAns = 1e9;
int maxAns = -1e9;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i != N; ++i)
        cin >> board[i];
    
    string expression = "";
    for (int i = 0; i != 4; ++i) {
        cin >> opMath[i];
    }

    for (int i = 0; i != 4; ++i) {
        while (opMath[i] > 0) {
            expression += to_string(i);
            opMath[i] -= 1;
        }
    }

    do {
        int value = board[0];
        // + - * /
        for (int i = 0; i != N - 1; ++i) {
            int op = expression[i];
            if (op - '0' == 0) {
                value = value + board[i + 1]; 
            }
            else if (op - '0' == 1) {
                value = value - board[i + 1];
            }
            else if (op - '0' == 2) {
                value = value * board[i + 1];
            }
            else if (op - '0' == 3) {
                if (value < 0) {
                    value *= -1;
                    value = value / board[i + 1];
                    value *= -1;
                }
                else {
                    value = value / board[i + 1];
                }
            }
        }
        maxAns = max(maxAns, value);
        minAns = min(minAns, value);
    } while (next_permutation(expression.begin(), expression.end()));

    cout << maxAns << '\n' << minAns;
}