// Problem: UVA11192 Group Reverse
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11192
// Create Time: 2025-10-16 11:19:11

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
string s;

signed main() {
	while (scanf("%d", &n) == 1) {
		if (!n) break;
		cin >> s;
		int grp_len = s.length() / n;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < grp_len; j++)
				putchar(s[grp_len * i - j - 1]);
		putchar('\n');
	}
	return 0;
}