<<<<<<< HEAD
// Problem: UVA10668 Expanding Rods
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10668
// Create Time: 2025-07-14 12:14:55

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

double l,t,c,ll;
double L,R,mid,theta;
double ans;
const double pi=acos(-1.0);

bool chk(double r) {
	theta=asin((l/2)/r);
	return r*theta*2>=ll;
}

signed main() {
	while (scanf("%lf%lf%lf",&l,&t,&c)==3) {
		if (l<0) break;
		ll=(1+t*c)*l;
		// >_<   ???
		if (fabs(t*c)<=1e-9) {
			printf("0.000\n");
			continue;
		}
		L=0; R=1e9;
		while (R-L>=1e-6) {
			mid=(L+R)/2;
			if (chk(mid)) {
				L=mid;
				ans=mid;
			}
			else R=mid;
		}
		printf("%.3f\n",ans-ans*cos(theta));
	}
	return 0;
=======
// Problem: UVA10668 Expanding Rods
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10668
// Create Time: 2025-07-14 12:14:55

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

double l,t,c,ll;
double L,R,mid,theta;
double ans;
const double pi=acos(-1.0);

bool chk(double r) {
	theta=asin((l/2)/r);
	return r*theta*2>=ll;
}

signed main() {
	while (scanf("%lf%lf%lf",&l,&t,&c)==3) {
		if (l<0) break;
		ll=(1+t*c)*l;
		// >_<   ???
		if (fabs(t*c)<=1e-9) {
			printf("0.000\n");
			continue;
		}
		L=0; R=1e9;
		while (R-L>=1e-6) {
			mid=(L+R)/2;
			if (chk(mid)) {
				L=mid;
				ans=mid;
			}
			else R=mid;
		}
		printf("%.3f\n",ans-ans*cos(theta));
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}