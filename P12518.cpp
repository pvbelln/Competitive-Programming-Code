<<<<<<< HEAD
// Problem: P12518 「MSTOI-R1」Easy question
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P12518
// Create Time: 2025-05-17 20:13:45

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

int n,q;
long long sum[21][1000005];
long long tmp,now;
const long long mod=998244353;
int x,l,r,k;

signed main() {
	r(n); r(q);
	for (int i=1;i<=n;i++) {
		r(tmp);
		sum[1][i]=tmp;
		now=tmp;
		sum[1][i]+=sum[1][i-1];
//		sum[1][i]%=mod;
		for (int j=2;j<=20;j++) {
			now*=tmp;
			now%=mod;
			sum[j][i]=sum[j][i-1]+now;
			sum[j][i]%=mod;
		}
	}
	/*
	for (int i=1;i<=20;i++) {
		for (int j=1;j<=n;j++)
			printf("%lld ",sum[i][j]);
		printf("\n");
	}
	*/
	while (q--) {
		r(x);
		if (x==1) {
			r(l); r(r);
			printf("%d\n",(sum[1][r]-sum[1][l-1])%mod);
		}
		else if (x==2) {
			r(l); r(r); r(k);
			printf("%d\n",(sum[k][r]-sum[k][l-1]+mod)%mod);
		}
		else {
			r(l); r(r);
			double ave=(sum[1][r]-sum[1][l-1])/2.0;
			long long ans=((((r-l+1)*(sum[2][r]-sum[2][l-1]+mod))%mod)-(((sum[1][r]-sum[1][l-1])%mod)*((sum[1][r]-sum[1][l-1])%mod))%mod)+mod;
			printf("%lld\n",ans%mod);
		}
	}
	return 0;
=======
// Problem: P12518 「MSTOI-R1」Easy question
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P12518
// Create Time: 2025-05-17 20:13:45

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

int n,q;
long long sum[21][1000005];
long long tmp,now;
const long long mod=998244353;
int x,l,r,k;

signed main() {
	r(n); r(q);
	for (int i=1;i<=n;i++) {
		r(tmp);
		sum[1][i]=tmp;
		now=tmp;
		sum[1][i]+=sum[1][i-1];
//		sum[1][i]%=mod;
		for (int j=2;j<=20;j++) {
			now*=tmp;
			now%=mod;
			sum[j][i]=sum[j][i-1]+now;
			sum[j][i]%=mod;
		}
	}
	/*
	for (int i=1;i<=20;i++) {
		for (int j=1;j<=n;j++)
			printf("%lld ",sum[i][j]);
		printf("\n");
	}
	*/
	while (q--) {
		r(x);
		if (x==1) {
			r(l); r(r);
			printf("%d\n",(sum[1][r]-sum[1][l-1])%mod);
		}
		else if (x==2) {
			r(l); r(r); r(k);
			printf("%d\n",(sum[k][r]-sum[k][l-1]+mod)%mod);
		}
		else {
			r(l); r(r);
			double ave=(sum[1][r]-sum[1][l-1])/2.0;
			long long ans=((((r-l+1)*(sum[2][r]-sum[2][l-1]+mod))%mod)-(((sum[1][r]-sum[1][l-1])%mod)*((sum[1][r]-sum[1][l-1])%mod))%mod)+mod;
			printf("%lld\n",ans%mod);
		}
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}