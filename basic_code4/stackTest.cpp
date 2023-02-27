#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000005;
int s[MAX];
int pos = -1;

void push(int x){
	s[++pos] = x;
}

void pop(){
	if(pos > -1) pos--;
}

int top(){
	if(pos > -1) return s[pos];
	else return -1;
}


int main(){
	fill(s, s+MAX, 0);
	int arr[10];
	int l = 10;
	for(int i = 0; i < l; i++){
		arr[i] = i + 5;
	}

    for(int i = 0; i < l; i++){
		push(arr[i]);
	}
	
	for(int i = 0; i < l; i++){
		cout << "최 상단 값 = " << top() << "\n";
		pop();
	}
	
}