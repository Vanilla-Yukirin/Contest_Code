/**************************************************************
 * Problem: 
 * Author: Allinaw
 * Date: 
 * E-Mail: Allinaw@outlook.com
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
bool cmp(int x,int y)
{
	return x>y;
}


vector<int>edge[N];
int f[N],dep[N];
int max1[N],max2[N];
void dfs(int x)
{
	vector<int>deps;
	for(unsigned int i=0;i<edge[x].size();i++)
	{
		if(edge[x][i]==f[x]) continue;
		f[edge[x][i]]=x;
		dfs(edge[x][i]);
		deps.push_back(dep[edge[x][i]]+1);
	}
	sort(deps.begin(),deps.end(),cmp);
	if(deps.size()==0) dep[x]=0,max1[x]=0,max2[x]=0;
	if(deps.size()==1) dep[x]=max1[x]=deps[0],max2[x]=0;
	if(deps.size()>=2) dep[x]=max1[x]=deps[0],max2[x]=deps[1];
}


int n,q;

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
		for(int i=1;i<n;i++)
		{
			int a,b;cin>>a>>b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		dfs(1);
		cin>>q;
		while(q--)
		{
			int a,b;
			cin>>a>>b;
			int x=a;
			int ans=dep[a];
			int son_dep=dep[a];
			for(int tt=1;tt<=b;tt++)
			{
				x=f[x];
				if(x==0) break;
				if(max1[x]==son_dep)
				{
					if(max2[x]) ans=max(ans,tt+max2[x]);
				}
				else
				{
					ans=max(ans,tt+max1[x]);
				}
				son_dep=dep[x];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
