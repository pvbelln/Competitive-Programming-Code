// Problem: UVA120 煎饼 Stacks of Flapjacks
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA120
// Create Time: 2025-03-03 23:04:47

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<sstream>
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

string inp;
int a[35],sorted[35];
int n,pos,flag;

void deb() {
	for (int i=1;i<=n;i++)
		cerr<<" "<<a[i];
	cerr<<"\n";
}

signed main() {
	while (getline(cin,inp)) {
		stringstream ss(inp);
		n=flag=1;
		while (ss>>a[n]) {
			sorted[n]=a[n];
			n++;
		}
		n--;
		for (int i=1;i<=n;i++) {
			if (i!=1) putchar(' ');
			printf("%d",a[i]);
		}
		putchar('\n');
		reverse(a+1,a+n+1);
		sort(sorted+1,sorted+n+1);
		reverse(sorted+1,sorted+n+1);
		for (int i=1;i<=n;i++) {
			if (a[i]!=sorted[i]) {
				for (pos=1;pos<=n;pos++)
					if (a[pos]==sorted[i])
						break;
				if (pos!=n) {
					if (!flag) printf(" %d",pos);
					else printf("%d",pos);
					flag=0;
					reverse(a+pos,a+n+1);
//					deb();
					printf(" %d",i);
					reverse(a+i,a+n+1);
//					deb();
				}
				else {
					if (!flag) printf(" %d",i);
					else printf("%d",i);
					flag=0;
					reverse(a+i,a+n+1);
//					deb();
				}
			}
		}
		if (!flag) putchar(' ');
		printf("0\n");
	}
	return 0;
}