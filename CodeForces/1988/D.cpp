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
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;



#define N 300010

int n;
int head[N],nxt[N*2],ver[N*2],cnt;
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
}


LL a[N];

#define K 25
#define inf (1ll<<62)
LL dp[N][K+5];

void dfs(int x,int f)
{
	for(int i=1;i<=K;i++)
	{
		dp[x][i]=a[x]*i;
	}
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==f) continue;
		dfs(y,x);
		for(int j=1;j<=K;j++)//点x将被第j次选
		{
			LL mn=inf;
			for(int k=1;k<=K;k++)//相邻点y将被第k次选
			{
				if(j!=k)
				{
					mn=min(mn,dp[y][k]);
				}
			}
			dp[x][j]+=mn;
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			int x,y;cin>>x>>y;
			insert(x,y);
			insert(y,x);
		}
		
		dfs(1,0);
		
		LL ans=inf;
		for(int i=1;i<=K;i++)
		{
			ans=min(ans,dp[1][i]);
		}
		
		cout<<ans<<endl;
		
		
		for(int i=1;i<=cnt;i++)
		{
			head[i]=nxt[i]=ver[i]=0;
		}
		cnt=0;
	}
	return 0;
}
