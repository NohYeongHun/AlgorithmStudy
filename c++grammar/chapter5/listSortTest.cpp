#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::string;

struct Test_info
{
    /* data */
    std::string name;
};

bool comp(const Test_info& x, const Test_info& y)
{
    return x.name < y.name;
}

int main(){
    vector<Test_info> v;
    list<Test_info> l;

    int T;
    cout << "Test case = ";
    cin >> T;
    Test_info record;
    while(T--){
        cin >> record.name;
        v.push_back(record);
        l.push_back(record);
    }

    sort(v.begin(), v.end(), comp);
    l.sort(comp);

    cout << "vector = " << "\n";
    for(vector<Test_info>::iterator iter = v.begin(); iter != v.end(); iter++){
        cout << "이름 정렬 확인 = " << iter -> name << "\n";
    }

    cout << "list = " << "\n";
    for(list<Test_info>::iterator iter = l.begin(); iter != l.end(); iter++){
        cout << "이름 정렬 확인 = " << iter -> name << "\n";
    }


}