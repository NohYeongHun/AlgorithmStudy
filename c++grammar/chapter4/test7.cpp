#include<iostream>
#include<ios>
#include<iomanip>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<double> vec;

    double x;
    while(cin >> x){
        vec.push_back(x);
    }

    vector<double>::size_type size;
    size = vec.size();

    double sum;
    for(vector<double>::iterator iter = vec.begin(); iter!= vec.end(); iter++){
        sum += *iter;
    }

    cout << "double 평균 = " << sum / size;

}