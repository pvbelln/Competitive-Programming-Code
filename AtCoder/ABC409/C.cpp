// C - Equilateral Triangle
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

int l,n;
int a[300005];
long long ans;
int nowpos;

signed main() {
	r(n); r(l);
	if (l%3 != 0) {
		puts("0");
		return 0;
	}
	a[0]=1;
	n--;
	while (n--) {
		nowpos+=read();
		nowpos%=l;
		a[nowpos]++;
	}
	for (int i=0;i<l;i++) {
		if (a[i] && a[(i+l/3)%l] && a[(i+2*l/3)%l])
			ans+=1ll*a[i] * a[(i+l/3)%l] * a[(i+2*l/3)%l],
			a[i] = a[(i+l/3)%l] = a[(i+2*l/3)%l] = 0;
	}
	printf("%lld\n",ans);
	return 0;
}