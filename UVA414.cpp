// Problem: UVA414 Machined Surfaces
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA414
// Create Time: 2025-10-09 10:41:39

#include <iostream>

#ifdef ONLINE_JUDGE
#    define getchar getchar_unlocked
#endif

using namespace std;

inline int read() {
    char c = getchar();
    int  x = 0, f = 1;
    for (; !isdigit(c); c = getchar())
        if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
    return x * f;
}

#define r(a) (a) = read()

int    N;
int    ans, minn, now;
string s;

signed main() {
    while (1) {
        cin >> N;
        ans  = 0;
        minn = 100;
        cin.ignore();
        if (!N) break;
        for (int i = 1; i <= N; i++) {
            getline(cin, s);
            now = 0;
            for (auto c : s)
                if (c == ' ') now++;
            minn = min(minn, now);
            ans += now;
        }
        ans -= minn * N;
        printf("%d\n", ans);
    }
    return 0;
}