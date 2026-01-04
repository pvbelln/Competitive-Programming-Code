// Problem: P4057 [Code+#1] 晨跑
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4057
// Create Time: 2025-06-23 19:51:58

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
#define int long long
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

int a,b,c;

signed main() {
	cin>>a>>b>>c;
	int x=a*b/__gcd(a,b);
	cout<<x*c/__gcd(x,c)<<"\n";
	return 0;
}