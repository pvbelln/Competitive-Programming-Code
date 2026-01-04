<<<<<<< HEAD
// Problem: P1589 泥泞路
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1589
// Create Time: 2025-06-17 21:00:37

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

int n,l,x,ans,add;
struct node {
	int l,r;
	bool operator < (const node& a) const {
		return l<a.l;
	}
}mud[10005];

signed main() {
	r(n); r(l);
	for (int i=1;i<=n;i++) {
		r(mud[i].l); r(mud[i].r);
	}
	sort(mud+1,mud+n+1);
	for (int i=1;i<=n;i++) {
		x=max(x,mud[i].l);
		if (x<mud[i].r) {
			ans+=(add=(mud[i].r-x)/l);
			if (x+add*l<mud[i].r) add++, ans++;
			x+=add*l;
		}
	}
	printf("%d\n",ans);
	return 0;
=======
// Problem: P1589 泥泞路
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1589
// Create Time: 2025-06-17 21:00:37

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

int n,l,x,ans,add;
struct node {
	int l,r;
	bool operator < (const node& a) const {
		return l<a.l;
	}
}mud[10005];

signed main() {
	r(n); r(l);
	for (int i=1;i<=n;i++) {
		r(mud[i].l); r(mud[i].r);
	}
	sort(mud+1,mud+n+1);
	for (int i=1;i<=n;i++) {
		x=max(x,mud[i].l);
		if (x<mud[i].r) {
			ans+=(add=(mud[i].r-x)/l);
			if (x+add*l<mud[i].r) add++, ans++;
			x+=add*l;
		}
	}
	printf("%d\n",ans);
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}