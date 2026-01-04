// B - Citation
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

int n;
int a[105];
int ans;

signed main() {
	r(n);
	for (int i=1;i<=n;i++)
		r(a[i]);
	sort(a+1,a+n+1,[](int x,int y) {
		return x>y;
	});
	for (int i=n;i>=0;i--) {
		if (a[i]>=i) {
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}