// Problem: P14631 [2018 KAIST RUN Fall] Repetitive Palindrome
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P14631
// Create Time: 2025-11-29 00:47:05

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

string s;
int n;

signed main() {
	cin >> s >> n;
	string tmp = s;
	reverse(s.begin(), s.end());
	if (s == tmp)
		puts("YES");
	else
		puts("NO");
	return 0;
}