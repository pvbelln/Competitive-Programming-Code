<<<<<<< HEAD
// Problem: UVA10082 WERTYU
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10082
// Create Time: 2025-02-16 23:30:46

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

string s="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
string inp;

signed main() {
	while (getline(cin,inp)) {
		for (auto c:inp) {
			if (c!=' ')
				putchar(s[s.find(c)-1]);
			else putchar(' ');
		}
		putchar('\n');
	}
	return 0;
=======
// Problem: UVA10082 WERTYU
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10082
// Create Time: 2025-02-16 23:30:46

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

string s="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
string inp;

signed main() {
	while (getline(cin,inp)) {
		for (auto c:inp) {
			if (c!=' ')
				putchar(s[s.find(c)-1]);
			else putchar(' ');
		}
		putchar('\n');
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}