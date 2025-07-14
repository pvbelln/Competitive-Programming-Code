// Problem: Add Two Numbers
// Contest: Kattis
// URL: https://open.kattis.com/problems/addtwonumbers
// Create Time: 2025-06-18 19:12:52

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
//#include<unordered_map>
//#define map unordered_map
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
using namespace std;
/*================*/

inline int read() {
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

#define r(a) (a)=read()

int a,b;

signed main() {
	cin>>a>>b;
	cout<<a+b<<"\n";
	return 0;
}