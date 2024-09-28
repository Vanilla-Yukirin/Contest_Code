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



#define N 1000010

int n,m;

int head[N],ver[N],w[N],nxt[N],cnt;
void add(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	w[cnt]=z;
}


LL val[N];
bool book[N];
void dfs(int x,int f,LL p)
{
	val[x]=p;
	book[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==f||book[y]) continue;
		dfs(y,x,p+w[i]);
	}
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
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			int x,y,z;cin>>x>>y>>z;
			add(x,y,z);
			add(y,x,-z);
		}
		for(int i=1;i<=n;i++)
		{
			if(book[i]==0) dfs(i,0,0);
		}
		
		
		for(int i=1;i<=n;i++)
		{
			cout<<val[i]<<" ";
		}
	}
	return 0;
}
