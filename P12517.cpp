// Problem: P12517 「MSTOI-R1」MST Find
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P12517
// Create Time: 2025-05-17 20:02:27

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

string ss;
int m,s,t;

signed main() {
	getline(cin,ss);
	for (auto c:ss) {
		if (c=='M'||c=='m') m++;
		if (c=='S'||c=='s') s++;
		if (c=='T'||c=='t') t++;
	}
	cout<<m<<" "<<s<<" "<<t<<"\n";
	return 0;
}
