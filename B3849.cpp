// Problem: B3849 [GESP样题 三级] 进制转换
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B3849
// Create Time: 2025-07-02 22:03:31

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

int n,base;
vector<int> v;

signed main() {
	r(n); r(base);
	while (n) {
		v.push_back(n%base);
		n/=base;
	}
	for (int i=v.size()-1;i>=0;i--) {
		if (v[i]<=9) putchar(v[i]+'0');
		else putchar(v[i]+'A'-10);
	}
	putchar('\n');
	return 0;
}