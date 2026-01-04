<<<<<<< HEAD
// Problem: P1679 神奇的四次方数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1679
// Create Time: 2025-06-14 20:00:06

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

int dp[100005];
int m;

signed main() {
	r(m);
	memset(dp,0x3f,sizeof dp);
	dp[1]=1;
	dp[0]=0;
	for (int i=2;i<=m;i++)
		for (int j=1;j*j*j*j<=i;j++)
			dp[i]=min(dp[i],dp[i-j*j*j*j]+1);
	printf("%d\n",dp[m]);
	return 0;
=======
// Problem: P1679 神奇的四次方数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1679
// Create Time: 2025-06-14 20:00:06

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

int dp[100005];
int m;

signed main() {
	r(m);
	memset(dp,0x3f,sizeof dp);
	dp[1]=1;
	dp[0]=0;
	for (int i=2;i<=m;i++)
		for (int j=1;j*j*j*j<=i;j++)
			dp[i]=min(dp[i],dp[i-j*j*j*j]+1);
	printf("%d\n",dp[m]);
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}