<<<<<<< HEAD
#include<iostream>
using namespace std;

inline int read() {
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

#define r(a) (a)=read()

int kase,T,n,x,y,p,q;

signed main() {
	r(kase);
	while (kase--) {
		r(T); r(n);
		while (T--) {
			r(x); r(y); r(p); r(q);
			if (abs(x-y)%2 != abs(p-q)%2)
				puts("no move");
			else if (x==p && y==q)
				printf("0\n");
			else if (x+y==p+q || x-y==p-q)
				printf("1\n");
			else
				printf("2\n");
		}
	}
	return 0;
=======
#include<iostream>
using namespace std;

inline int read() {
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

#define r(a) (a)=read()

int kase,T,n,x,y,p,q;

signed main() {
	r(kase);
	while (kase--) {
		r(T); r(n);
		while (T--) {
			r(x); r(y); r(p); r(q);
			if (abs(x-y)%2 != abs(p-q)%2)
				puts("no move");
			else if (x==p && y==q)
				printf("0\n");
			else if (x+y==p+q || x-y==p-q)
				printf("1\n");
			else
				printf("2\n");
		}
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}