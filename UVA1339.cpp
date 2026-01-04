<<<<<<< HEAD
// Problem: 1339 - Ancient Cipher
// Contest: UVa Online Judge
// Create Time: 2025-06-19 20:55:55

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
//#define getchar getchar_unlocked
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

string a,b;
int occ1[30],occ2[30];
bool f;

signed main() {
	while (cin>>a>>b) {
		memset(occ1,0,sizeof occ1);
		memset(occ2,0,sizeof occ2);
		for (int i=0;i<(int)a.length();i++) occ1[a[i]-'A']++;
		for (int i=0;i<(int)b.length();i++) occ2[b[i]-'A']++;
		sort(occ1,occ1+27);
		sort(occ2,occ2+27);
		f=0;
		for (int i=0;i<26;i++)
			if (occ1[i]!=occ2[i]) {
				f=1;
				break;
			}
		if (f) puts("NO");
		else puts("YES");
		break;
	}
	return 0;
=======
// Problem: 1339 - Ancient Cipher
// Contest: UVa Online Judge
// Create Time: 2025-06-19 20:55:55

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
//#define getchar getchar_unlocked
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

string a,b;
int occ1[30],occ2[30];
bool f;

signed main() {
	while (cin>>a>>b) {
		memset(occ1,0,sizeof occ1);
		memset(occ2,0,sizeof occ2);
		for (int i=0;i<(int)a.length();i++) occ1[a[i]-'A']++;
		for (int i=0;i<(int)b.length();i++) occ2[b[i]-'A']++;
		sort(occ1,occ1+27);
		sort(occ2,occ2+27);
		f=0;
		for (int i=0;i<26;i++)
			if (occ1[i]!=occ2[i]) {
				f=1;
				break;
			}
		if (f) puts("NO");
		else puts("YES");
		break;
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}