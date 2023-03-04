#include<iostream>
#include<vector>
#include<string>

// space return true , not space return false
bool space(char c)
{
    return isspace(c);
}

// space return false , not space return true
bool not_space(char c)
{
    return !isspace(c);
}


using namespace std;
int main(){
    typedef string::const_iterator iter;
    string str;
    getline(cin, str);
    
    vector<string> a;
    a.push_back(str);
    vector<string> b(a);

    for (vector<string>::iterator iter = a.begin(); iter != a.end(); iter++){
        cout << *iter << "\n";
    }

    for (vector<string>::iterator iter = b.begin(); iter != b.end(); iter++){
        cout << *iter << "\n";
    }
}
