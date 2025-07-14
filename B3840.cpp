// Problem: B3840 [GESP202306 二级] 找素数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B3840
// Create Time: 2025-06-30 10:25:08

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

int a,b,ans;

bool isprime(int x) {
	if (x==2) return 1;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return 0;
	return 1;
}

signed main() {
	r(a); r(b);
	for (int i=a;i<=b;i++)
		ans+=isprime(i);
	printf("%d\n",ans);
	return 0;
}