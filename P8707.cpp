// Problem: P8707 [蓝桥杯 2020 省 AB1] 走方格
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8707
// Create Time: 2025-07-03 11:51:02

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

int n,m;
int a[35][35];

signed main() {
	r(n); r(m);
	for (int i=1;i<=30;i++)
		a[1][i]=a[i][1]=1;
	for (int i=2;i<=n;i++)
		for (int j=2;j<=m;j++) {
			if (i%2==0 && j%2==0) continue;
			a[i][j]=a[i-1][j]+a[i][j-1];
		}
	printf("%d\n",a[n][m]);
	return 0;
}