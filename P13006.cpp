// Problem: P13006 【MX-X13-T1】「KDOI-12」在现实和志向中选择现实，否则会一个都得不到的。
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P13006
// Create Time: 2025-06-30 11:16:18

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

string a,b,c,d,e;

signed main() {
	cin>>a>>b>>c>>d>>e;
	if (a==c && e=="weak.") puts("Plang.");
	else puts("Not plang.");
	return 0;
}