// Problem: P2777 [AHOI2016初中组] 自行车比赛
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2777
// Create Time: 2025-07-03 11:07:04

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

int n,ans,maxx;
int a[300005];

signed main() {
	r(n);
	for (int i=1;i<=n;i++)
		r(a[i]);
	sort(a+1,a+n+1,[](int a,int b) {
		return a>b;
	});
	for (int i=1;i<=n;i++)
		maxx=max(maxx,a[i]+i);
	for (int i=1;i<=n;i++) {
		if (a[i]+n>=maxx)
			ans++;
		else
			break;
	}
	printf("%d\n",ans);
	return 0;
}