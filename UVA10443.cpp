// Problem: UVA10443 Rock, Scissors, Paper
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10443
// Create Time: 2025-09-29 22:47:19

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
// #include<unordered_map>
// #define map unordered_map
#ifdef ONLINE_JUDGE
#    define getchar getchar_unlocked
#endif
using namespace std;
/*================*/

inline int read() {
    char c = getchar();
    int  x = 0, f = 1;
    for (; !isdigit(c); c = getchar())
        if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
    return x * f;
}

#define r(a) (a) = read()

int T;
int r, c, n;
char m[105][105], tmp[105][105];
int dirx[] = {-1, 0, 0, 1}, diry[] = {0, 1, -1, 0};

void work() {
	int nx, ny;
	char now, nxt;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			tmp[i][j] = m[i][j];
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			now = m[i][j];
			for (int k = 0; k < 4; k++) {
				nx = i + dirx[k];
				ny = j + diry[k];
				nxt = m[nx][ny];
				if (now == 'R' && nxt == 'S')
					tmp[nx][ny] = 'R';
				if (now == 'S' && nxt == 'P')
					tmp[nx][ny] = 'S';
				if (now == 'P' && nxt == 'R')
					tmp[nx][ny] = 'P';
			}
		}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			m[i][j] = tmp[i][j];
}

signed main() {
	r(T);
	while (T--) {
		r(r); r(c); r(n);
		for (int i = 1; i <= r; i++)
			scanf("%s", m[i] + 1);
		while (n--)
			work();
		for (int i = 1; i <= r; i++)
			printf("%s\n", m[i] + 1);
		if (T)
			puts("");
	}
}