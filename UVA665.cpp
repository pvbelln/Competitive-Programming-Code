// Problem: UVA665 False coin
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA665
// Create Time: 2025-11-13 23:18:34

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

int M, N, K;
int ansCoin;
struct node {
	int L[105], R[105];
	int cnt, stat;  // = 0, < -1, > 1
} result[105];

bool judge(int ID, int x) {
	for (int i = 0; i < K; i++) {
		int L, R;
		L = R = 0;
		int num = result[i].cnt;
		for (int j = 0; j < num; j++) {
			if (result[i].L[j] == ID)
				L += x;
			if (result[i].R[j] == ID)
				R += x;
		}
		if (L < R)
			if (result[i].stat != -1)
				return false;
		if (L > R)
			if (result[i].stat != 1)
				return false;
		if (L == R)
			if (result[i].stat != 0)
				return false;
	}
	return true;
}

signed main() {
	r(M);
	for (int _ = 0; _ < M; _++) {
		r(N); r(K);
		for (int i = 0; i < K; i++) {
			int num = read();
			result[i].cnt = num;
			for (int j = 0; j < num; j++)
				r(result[i].L[j]);
			for (int j = 0; j < num; j++)
				r(result[i].R[j]);
			char op[5];
			scanf("%s", op);
			if (op[0] == '<')
				result[i].stat = -1;
			else if (op[0] == '=')
				result[i].stat = 0;
			else
				result[i].stat = 1;
		}
		ansCoin = 0;
		if (_)
			printf("\n");
		bool flag = 1;
		for (int i = 1; i <= N; i++) {
			if (judge(i, 1) || judge(i, -1)) {
				if (ansCoin) {
					flag = 0;
					break;
				}
				ansCoin = i;
			}
		}
		printf("%d\n", (flag ? ansCoin : 0));
	}
	return 0;
}

// 枚举 暴力