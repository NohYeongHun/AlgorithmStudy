#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<cctype>
 

using std::vector;
using std::list;
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::isspace;
using std::max;

// scan a string of texts, split into words, return a vector that contains these words.
// (S5.6/88)
vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;
 
    // invariant: we have processed characters original value of [i, i)
    while (i != s.size() )
    {
        // ignore leading blanks
        // invariant: characters in range [original i, current i)
        while (i != s.size() && isspace(s[i]))
            ++i;
 
        // find end of next word
        string_size j = i;
 
        // invariant: none of the characters in range [original j, current j) is a space
        while (j != s.size() && !isspace(s[j]))
            ++j;
 
        // if we found some non-whitespace characters
        if (i != j)
            // copy from s starting at i and taking j - i chars
            ret.push_back(s.substr(i, j - i));
            i = j;
    }
    return ret;
}

void pop_front(vector<string> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}

/*
    문장의 시작 위치, 끝 위치.
    끝위치가 앞의 문자열
    시작위치가 뒤의 문자열로 출력.
*/ 
void permutedCout(const vector<string>& sentences,
                  const vector<string>::size_type start,
                  const vector<string>::size_type end){

}

string::size_type width(const vector<string>& v){
    string::size_type maxlen = 0;

    for(vector<string>::size_type i = 0; i!= v.size(); ++i){
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;

}

vector<string> v, temp;
vector<string>::size_type tempStart, tempEnd, size;
string::size_type maxlen;
string s, t;

int main(){
    
    
    while(getline(cin, s)){
        temp = split(s);
        // 문장의 시작 위치, 끝 위치
        tempStart = 0, tempEnd = temp.size();
        size = temp.size();
        cout << "cur sentence = " << s << "\n";
        for(vector<string>::size_type size = 0; size != temp.size(); size++){
            maxlen = s.size();
            
            cout << "\n";
            string gap(4, ' ');
            
            string front;
            for(vector<string>::size_type i = tempEnd; i!= temp.size(); i++){
                cout << temp[i] << " ";
                maxlen -= (temp[i].size() + 1);
            }

            // 줄 맞춤
            cout << string(maxlen, ' ');

            cout << gap << "|" << gap;
            for(vector<string>::size_type i = 0; i!= tempEnd; i++){
                cout << temp[i] << " ";
            }
            t = temp[0];
            pop_front(temp);
            temp.push_back(t);
            tempEnd--;
            cout << "\n";
        }
        
    }

}