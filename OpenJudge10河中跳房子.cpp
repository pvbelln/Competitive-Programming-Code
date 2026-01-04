// Problem: 10:河中跳房子
// Contest: OpenJudge - NOI - 1.11编程基础之二分查找
// URL: http://noi.openjudge.cn/ch0111/10/?lang=zh_CN
// Create Time: 2025-07-10 12:59:12

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

int l,m,n;
int d[50005];
int L,R,mid,ans;

bool chk(int x) {
	int cnt,now;
	cnt=now=0;
	for (int i=1;i<=n+1;i++) {
		if (d[i]-now<x) cnt++;
		else now=d[i];
	}
	return cnt<=m;
}

signed main() {
	r(l); r(n); r(m);
	for (int i=1;i<=n;i++)
		r(d[i]);
	d[n+1]=l;
	sort(d+1,d+n+2);
	R=l;
	while (L<=R) {
		mid=(L+R)/2;
		if (chk(mid)) {
			L=mid+1;
			ans=mid;
		}
		else R=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}