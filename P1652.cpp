// Problem: P1652 圆
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1652
// Create Time: 2025-06-14 14:04:09

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

int n,ans;
int x[55],y[55],r[55];
int X1,Y1,X2,Y2;
bool in_circ[55];

signed main() {
	r(n);
	for (int i=1;i<=n;i++) r(x[i]);
	for (int i=1;i<=n;i++) r(y[i]);
	for (int i=1;i<=n;i++) r(r[i]);
	r(X1);r(Y1);r(X2);r(Y2);
	for (int i=1;i<=n;i++)
		if (hypot(X1-x[i],Y1-y[i])<r[i]*1.0)
			in_circ[i]=1, ans++;
	in_circ[0]=1;
	for (int i=1;i<=n;i++)
		if (hypot(X2-x[i],Y2-y[i])<r[i]*1.0) {
			if (in_circ[i]) ans--;
			else ans++;
		}
	printf("%d\n",ans);
	return 0;
}