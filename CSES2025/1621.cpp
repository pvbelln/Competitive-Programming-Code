// Problem: Distinct Numbers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1621
// Create Time: 2025-12-04 16:55:11

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

int n;
vector<int> v;

signed main() {
	r(n);
	for (int i = 0; i < n; i++)
		v.push_back(read());
	sort(v.begin(), v.end());
	printf("%d\n", unique(v.begin(), v.end()) - v.begin());
	return 0;
}