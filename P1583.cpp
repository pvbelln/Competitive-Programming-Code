// Problem: P1583 魔法照片
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1583
// Create Time: 2025-06-17 20:44:03

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

int n,k;
int e[15];

struct node {
	int id,val;
	bool operator < (const node&  a) const {
		if (a.val==val) return id<a.id;
		return val>a.val;
	}
}a[20005];

signed main() {
	r(n); r(k);
	for (int i=1;i<=9;i++) r(e[i]);
	r(e[0]);
	for (int i=1;i<=n;i++) {r(a[i].val);  a[i].id=i;}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) a[i].val+=e[i%10];
	sort(a+1,a+n+1);
	for (int i=1;i<=k;i++) printf("%d ",a[i].id);
	printf("\n");
	return 0;
}