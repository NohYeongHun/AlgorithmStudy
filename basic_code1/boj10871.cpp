#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x ;
    int array[n];
    for(int i = 0; i < n; i ++){
        cin >> array[i];
    }

    string result = "";

    for(int i = 0; i < n; i ++){
        if (array[i] < x){
            result += to_string(array[i]);
            result += " ";
        }
    }

    result.resize(result.size() - 1);
    cout << result;
    
    return 0;
}
