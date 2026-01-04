// Problem: UVA12150 Pole Position
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA12150
// Create Time: 2025-10-16 16:55:46

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

int N;

struct node {
	int id, num;
	bool operator < (const node& a) const {
		return num < a.num;
	}
}car[1005];

signed main() {
	while (1) {
		r(N);
		if (!N) break;
		memset(car, 0, sizeof car);
		for (int i = 1; i <= N; i++) {
			car[i] = {read(), i + read()};
		}
		sort(car + 1, car + 1 + N);
		bool f = 1;
		for (int i = 1; i <= N; i++) {
			if (car[i].num < 1 || car[i].num > N) {
				puts("-1");
				f = 0;
				break;
			}
			if (i < N && car[i].num == car[i + 1].num) {
				puts("-1");
				f = 0;
				break;
			}
		}
		if (f) {
			for (int i = 1; i <= N; i++) {
				printf("%d",car[i].id);
				if (i < N) printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}

/*
当前位次和变化位次加起来排序
有越界结果或重复结果直接无解
*/