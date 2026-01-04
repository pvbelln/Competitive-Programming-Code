<<<<<<< HEAD
// Problem: UVA401 回文词 Palindromes
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA401
// Create Time: 2025-02-18 23:22:23

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

string s;
char dictAlpha[]="A   3  HIL JM O   2TUVWXY5";
char dictNum[]="1SE Z  8 ";

string msg[]={"is not a palindrome.\n","is a regular palindrome.\n",
			  "is a mirrored string.\n","is a mirrored palindrome.\n"};

int result;

signed main() {
	while (cin>>s) {
		result=0;
		string tmp=s;
		reverse(tmp.begin(),tmp.end());
		if (tmp==s) result=1;
		tmp="";
		for (auto c:s) {
			if (isalpha(c))
				tmp+=dictAlpha[c-'A'];
			else
				tmp+=dictNum[c-'1'];
		}
		reverse(tmp.begin(),tmp.end());
		if (tmp==s) result+=2;
		cout<<s<<" -- "<<msg[result]<<"\n";
	}
	return 0;
=======
// Problem: UVA401 回文词 Palindromes
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA401
// Create Time: 2025-02-18 23:22:23

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

string s;
char dictAlpha[]="A   3  HIL JM O   2TUVWXY5";
char dictNum[]="1SE Z  8 ";

string msg[]={"is not a palindrome.\n","is a regular palindrome.\n",
			  "is a mirrored string.\n","is a mirrored palindrome.\n"};

int result;

signed main() {
	while (cin>>s) {
		result=0;
		string tmp=s;
		reverse(tmp.begin(),tmp.end());
		if (tmp==s) result=1;
		tmp="";
		for (auto c:s) {
			if (isalpha(c))
				tmp+=dictAlpha[c-'A'];
			else
				tmp+=dictNum[c-'1'];
		}
		reverse(tmp.begin(),tmp.end());
		if (tmp==s) result+=2;
		cout<<s<<" -- "<<msg[result]<<"\n";
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}