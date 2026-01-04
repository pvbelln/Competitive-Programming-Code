//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,a,m,ans;
map <int,bool> appeared;//记录是否出现过
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n>>a;
		m=1;
		ans=0;//别忘了初始化
		for(int i=1;i<=n;++i)
		{
			m*=10;
		}
		appeared.clear();//记得清空map
		while(!appeared[a])
		{
			appeared[a]=true;
			ans=max(a,ans);
			a*=a;
			while(a>=m)//若太大了就缩小
			{
				a/=10;
			}
		}
		cout<<ans<<endl;//输出
	}
	return 0;
}