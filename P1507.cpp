// Problem: P1507 NASA的食物计划
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1507
// Create Time: 2025-06-16 11:18:15

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

int H,T,n;
int h[55],t[55],K[55];
int f[405][405];

signed main() {
	r(H); r(T); r(n);
	for (int i=1;i<=n;i++) {
		r(h[i]); r(t[i]); r(K[i]);
	}
	for (int i=1;i<=n;i++)
		for (int j=H;j>=h[i];j--)
			for (int k=T;k>=t[i];k--)
				f[j][k]=max(f[j][k],f[j-h[i]][k-t[i]]+K[i]);
	printf("%d\n",f[H][T]);
	return 0;
}