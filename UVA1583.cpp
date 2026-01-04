// Problem: 1583 - Digit Generator
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=448&page=show_problem&problem=4458
// Create Time: 2025-08-23 16:02:34

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
int x;
int ans[100005];

signed main() {
	r(n);
	for (int i=1;i<=100000;i++) {
		int now=i,tmp=i;
		while (tmp>0) now+=tmp%10, tmp/=10;
		if (now<=100000)
			if ((!ans[now]) || ans[now]>i)
				ans[now]=i;
	}
	while (n--)
		printf("%d\n",ans[read()]);
	return 0;
}

