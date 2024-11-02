/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug
#endif

#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"

// 红色
#define DEBUG1(x)                     \
RED;                              \
cout << #x << " : " << x << endl; \
RESET;

// 绿色
#define DEBUG2(x)                     \
GREEN;                            \
cout << #x << " : " << x << endl; \
RESET;

// 蓝色
#define DEBUG3(x)                     \
BLUE;                             \
cout << #x << " : " << x << endl; \
RESET;

// 品红
#define DEBUG4(x)                     \
MAGENTA;                          \
cout << #x << " : " << x << endl; \
RESET;

// 青色
#define DEBUG5(x)                     \
CYAN;                             \
cout << #x << " : " << x << endl; \
RESET;

// 黄色
#define DEBUG6(x)                     \
YELLOW;                           \
cout << #x << " : " << x << endl; \
RESET;

#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;



#define N 400010


struct Edge{
	LL l,r,sum;
#define l(x) tree[x].l
#define r(x) tree[x].r
#define sum(x) tree[x].sum
}tree[N*4];
LL n,m; 
void build(LL l,LL r,LL p)
{
	l(p)=l,r(p)=r;
	if(l==r){sum(p)=0;return;}
	LL mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	sum(p)=sum(p<<1)+sum(p<<1|1);
}

void add(int p,int x)
{
	if(l(p)==r(p))
	{
		sum(p)++;
		return;
	}
	int mid=(l(p)+r(p))/2;
	if(x<=mid) add(p<<1,x);
	else add(p<<1|1,x);
	sum(p)=sum(p<<1)+sum(p<<1|1);
}
LL ask(LL l,LL r,LL p)
{
	if(l<=l(p)&&r>=r(p)) return sum(p);
	LL mid=(l(p)+r(p))>>1,val=0;
	if(l<=mid) val+=ask(l,r,p<<1);
	if(r>mid) val+=ask(l,r,p<<1|1);
	return val;
}

LL a[N],sum[N];
LL ans,SUM;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
//	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]%=m;
			
			sum[i]=sum[i-1]+a[i];
			sum[i]%=m;
		}
		build(0,m,1);
//		add(1,0);
		for(LL i=1;i<=n;i++)
		{
//			DEBUG1(i);
			
//			DEBUG2(SUM);
			ans+=sum[i]*i-SUM+m*ask(sum[i]+1,m,1);
			SUM+=sum[i];
//			DEBUG3(ask(sum[i]+1,m,1));
			add(1,sum[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}


/*


4 100
60 10 10 50 90

60 70 80 130 220

r-x<0 plus++
x>r? 有多少个左边的数字大于r？

3 4
2 5 0
a:2 1 0
s:2 3 0
S:
2-0+
*/
