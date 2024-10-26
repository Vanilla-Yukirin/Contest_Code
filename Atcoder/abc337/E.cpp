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



#define N 1000010
int f[N],sze[N],p[N];
int getf(int x)
{
	if(x==f[x]) return x;
	return f[x]=getf(f[x]);
}

void merge(int x,int y)
{
	x=getf(x);
	y=getf(y);
	if(x==y) return;
	if(sze[x]>sze[y]) swap(x,y);
	f[x]=y;
	sze[y]+=sze[x];
	sze[x]=0;
}
int n;
LL K;

int pp[N][20];
int ans[N];

LL pow2(LL b,LL p)
{
	LL a=2;
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans%p;
}

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
		cin>>n>>K;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i];
			f[i]=i;
			sze[i]=1;
		}
		
		for(int i=1;i<=n;i++)
		{
			merge(i,p[i]);
		}
		
		
		for(int i=1;i<=n;i++) pp[i][0]=p[i];
		for(int k=1;k<20;k++)
		{
			for(int i=1;i<=n;i++)
				pp[i][k]=pp[pp[i][k-1]][k-1];
		}
		for(int i=1;i<=n;i++)
		{
//			int kk=K%sze[getf(i)];
			int kk=(pow2(K,sze[getf(i)])-1+sze[getf(i)])%sze[getf(i)];
			ans[i]=p[i];
//			cout<<i<<" need jump "<<kk<<endl;
			for(int k=19;k>=0;k--)
			{
				if(kk&(1<<k))
				{
					ans[i]=pp[ans[i]][k];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
