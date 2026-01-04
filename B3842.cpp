// Problem: B3842 [GESP202306 三级] 春游
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B3842
// Create Time: 2025-07-02 10:29:32

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

bool a[105];
int n,m,cnt;

signed main() {
	r(n); r(m);
	while (m--)
		a[read()]=1;
	for (int i=0;i<n;i++)
		if (!a[i]) {
			printf("%d ",i);
			cnt++;
		}
	if (!cnt) printf("%d",n);
	printf("\n");
	return 0;
}