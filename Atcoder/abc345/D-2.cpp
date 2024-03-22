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



#define N 110

int n,h,w;
int a[N],b[N];

bool mp[N][N];
bool win;
int sum;
bool s[N][810];
bool check(int x1,int y1,int x2,int y2)
{
	for(int i=x1;i<=x2;i++)
	{
		for(int j=y1;j<=y2;j++)
		{
			if(i<1||i>h||j<1||j>w)
			{
				return 0;
			}
			else if(mp[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}
void fill(int x1,int y1,int x2,int y2)
{
	sum+=(x2-x1+1)*(y2-y1+1);
	for(int i=x1;i<=x2;i++)
	{
		for(int j=y1;j<=y2;j++)
		{
			mp[i][j]=1;
		}
	}
}
void unfill(int x1,int y1,int x2,int y2)
{
	sum-=(x2-x1+1)*(y2-y1+1);
	for(int i=x1;i<=x2;i++)
	{
		for(int j=y1;j<=y2;j++)
		{
			mp[i][j]=0;
		}
	}
}
bool checkall()
{
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
//			cout<<mp[i][j]<<" ";
			if(!mp[i][j]) return 0;
		}
//		cout<<endl;
	}
	return 1;
}

vector<int>vec;
void dfs(int x)
{
//	debug
	if(win) return;
	
	if(sum==h*w)
	{
		win=1;
		return;
	}
	if(x==vec.size())
	{
		return;
	}
	int y=vec[x];
	if(h*w-sum>=a[y]*b[y])
		for(int i=1;i<=h;i++)
		{
			if(i+a[y]-1>h&&i+b[y]-1>h) break;
			for(int j=1;j<=w;j++)
			{
				if(mp[i][j]) continue;
				if(j+a[y]-1>w&&j+b[y]-1>w) break;
				if(check(i,j,i+a[y]-1,j+b[y]-1))
				{
					fill(i,j,i+a[y]-1,j+b[y]-1);
					dfs(x+1);
					unfill(i,j,i+a[y]-1,j+b[y]-1);
				}
				
				if(check(i,j,i+b[y]-1,j+a[y]-1))
				{
					fill(i,j,i+b[y]-1,j+a[y]-1);
					dfs(x+1);
					unfill(i,j,i+b[y]-1,j+a[y]-1);
				}
			}
		}
	
	
	dfs(x+1);
	
	
}

void dfs1(int x,int now)
{
	if(win) return;
	if(now>h*w) return;
	if(now==h*w)
	{
		
		cout<<endl;
		dfs(0);
		return;
	}
	if(x==n+1)
	{
		return;
	}
	dfs1(x+1,now);
	vec.push_back(x);
	dfs1(x+1,now+a[x]*b[x]);
	vec.pop_back();
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
		cin>>n>>h>>w;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
		}
		dfs1(1,0);
		if(win) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
		
	}
	return 0;
}
