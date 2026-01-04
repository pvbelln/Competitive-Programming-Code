<<<<<<< HEAD
// Problem: UVA12195 Jingle Composing
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA12195
// Create Time: 2025-03-02 16:44:43

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

char s[205];
double dur['Z'+5]; //时值
double now;
const double eps=1e-8;  //精度控制
int ans,l;

signed main() {
	dur['W']=1.0;
	dur['H']=0.5;
	dur['Q']=0.25;
	dur['E']=0.125;
	dur['S']=0.0625;
	dur['T']=0.03125;
	dur['X']=0.015625;
	while (scanf("%s",s)==1 && s[0]!='*') {
		ans=0; now=0.0;
		l=strlen(s);
		for (int i=0;i<l;i++) {
			if (s[i]=='/') {
				if (fabs(now-1.0)<eps)
					ans++;
				now=0.0;
			}
			else now+=dur[(int)s[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}

/*
## UVA12195

### 题目大意

给你若干个音乐的小节和音符的时值，判断有多少个小节的音符时值之和为 $1$。

### 解题思路

直接按照题意模拟即可，不同音符的时值可以参考题目中的表格。

本题读入较为特别，需要注意是以 `/` 来分隔小节的，应在代码中加以注意。

### 参考代码

```cpp
// Problem: UVA12195 Jingle Composing
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA12195
// Create Time: 2025-03-02 16:44:43

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


inline int read() {
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

#define r(a) (a)=read()

char s[205];
double dur['Z'+5]; //时值
double now;
const double eps=1e-8;  //精度控制
int ans,l;

signed main() {
	dur['W']=1.0;
	dur['H']=0.5;
	dur['Q']=0.25;
	dur['E']=0.125;
	dur['S']=0.0625;
	dur['T']=0.03125;
	dur['X']=0.015625;
	while (scanf("%s",s)==1 && s[0]!='*') {
		ans=0; now=0.0;
		l=strlen(s);
		for (int i=0;i<l;i++) {
			if (s[i]=='/') {
				if (fabs(now-1.0)<eps)
					ans++;
				now=0.0;
			}
			else now+=dur[(int)s[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
```
=======
// Problem: UVA12195 Jingle Composing
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA12195
// Create Time: 2025-03-02 16:44:43

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

char s[205];
double dur['Z'+5]; //时值
double now;
const double eps=1e-8;  //精度控制
int ans,l;

signed main() {
	dur['W']=1.0;
	dur['H']=0.5;
	dur['Q']=0.25;
	dur['E']=0.125;
	dur['S']=0.0625;
	dur['T']=0.03125;
	dur['X']=0.015625;
	while (scanf("%s",s)==1 && s[0]!='*') {
		ans=0; now=0.0;
		l=strlen(s);
		for (int i=0;i<l;i++) {
			if (s[i]=='/') {
				if (fabs(now-1.0)<eps)
					ans++;
				now=0.0;
			}
			else now+=dur[(int)s[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}

/*
## UVA12195

### 题目大意

给你若干个音乐的小节和音符的时值，判断有多少个小节的音符时值之和为 $1$。

### 解题思路

直接按照题意模拟即可，不同音符的时值可以参考题目中的表格。

本题读入较为特别，需要注意是以 `/` 来分隔小节的，应在代码中加以注意。

### 参考代码

```cpp
// Problem: UVA12195 Jingle Composing
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA12195
// Create Time: 2025-03-02 16:44:43

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


inline int read() {
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

#define r(a) (a)=read()

char s[205];
double dur['Z'+5]; //时值
double now;
const double eps=1e-8;  //精度控制
int ans,l;

signed main() {
	dur['W']=1.0;
	dur['H']=0.5;
	dur['Q']=0.25;
	dur['E']=0.125;
	dur['S']=0.0625;
	dur['T']=0.03125;
	dur['X']=0.015625;
	while (scanf("%s",s)==1 && s[0]!='*') {
		ans=0; now=0.0;
		l=strlen(s);
		for (int i=0;i<l;i++) {
			if (s[i]=='/') {
				if (fabs(now-1.0)<eps)
					ans++;
				now=0.0;
			}
			else now+=dur[(int)s[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
```
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
*/