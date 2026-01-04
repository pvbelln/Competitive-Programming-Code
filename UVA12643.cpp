#include<cstdio>
int n,i,j;
int main() {
	while (scanf("%d%d%d",&n,&i,&j)==3) {
		i--;
		j--;
		printf("%d\n",32-__builtin_clz(i^j));
	}
	return 0;
}