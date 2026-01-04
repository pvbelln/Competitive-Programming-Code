// Problem: UVA12959 Strategy Game
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA12959
// Create Time: 2025-10-23 11:16:27

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

int J, R;

struct node {
	int id, sum;
	bool operator < (const node& a) const {
		if (a.sum == sum)
			return id > a.id;
		return sum > a.sum;
	}
}a[505];

signed main() {
	while (scanf("%d%d",&J, &R) == 2) {
		memset(a, 0, sizeof a);
		for (int i = 1; i <= J; i++)
			a[i].id = i;
		while (R--) {
			for (int i = 1; i <= J; i++)
				a[i].sum += read();
		}
		sort(a + 1, a + J + 1);
		printf("%d\n",a[1].id);
	}
	return 0;
}