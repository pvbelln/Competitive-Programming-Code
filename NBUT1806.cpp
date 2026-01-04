// Problem: [1086] Miku调教
// Contest: NBUT Online Judge
// URL: https://ac.2333.moe/Problem/view.xhtml?id=1086
// Create Time: 2025-07-09 13:52:27

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
//#define getchar getchar_unlocked
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

int H,M,S,tot;
int n;
int v[205],f[46805];

signed main() {
	while (scanf("%d:%d:%d",&H,&M,&S)==3) {
		memset(f,0,sizeof f);
		tot=H*3600+M*60+S;
		r(n);
		for (int i=1;i<=n;i++)
			r(v[i]);
		for (int i=1;i<=n;i++)
			for (int j=tot;j>=v[i];j--)
				f[j]=max(f[j],f[j-v[i]]+v[i]);
		printf("%d\n",f[tot]);
	}
	return 0;
}