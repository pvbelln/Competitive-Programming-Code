// Problem: P4053 [JSOI2007] 建筑抢修
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4053
// Create Time: 2025-06-23 19:41:24

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
long long tot;
struct node {
	int t1,t2;
}bui[150005];

priority_queue<int> q;

signed main() {
	r(n);
	for (int i=1;i<=n;i++) {
		r(bui[i].t1);
		r(bui[i].t2);
	}
	sort(bui+1,bui+1+n,[](node a,node b) {
		return a.t2<b.t2;
	});
	for (int i=1;i<=n;i++) {
		tot+=bui[i].t1;
		q.push(bui[i].t1);
		if (tot<=bui[i].t2) ans++;
		else {
			tot-=q.top();
			q.pop();
		}
	}
	printf("%d\n",ans);
	return 0;
}