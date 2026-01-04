// Problem: UVA696 How Many Knights
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA696
// Create Time: 2025-06-29 14:00:54

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

int x,y,ans;

signed main() {
	while (1) {
		r(x); r(y);
		if (!x) break;
		if (x==1 || y==1) ans=max(x,y);
		else if (x==2 || y==2) ans=max(x,y), ans=(ans/4)*4+2*min(ans%4,2);
		else ans=(x*y+1)/2;
		printf("%d knights may be placed on a %d row %d column board.\n",ans,x,y);
	}
	return 0;
}