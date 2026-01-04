// ABC409
// A - Conflict
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

int n;
string a,b;
bool f;

signed main() {
	cin>>n>>a>>b;
	for (int i=0;i<n;i++)
		if (a[i]=='o' && b[i]=='o') {
			f=1;
			break;
		}
	if (f) puts("Yes");
	else puts("No");
	return 0;
}