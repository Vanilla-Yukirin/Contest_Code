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



#define N 200010

int n,m;
vector<int>edge[N];
int dis[N];
int ans;
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
		while(m--)
		{
			int a,b;cin>>a>>b;
			edge[a].push_back(b);
		}
		queue<int>q;
		q.push(1);
		while(q.size())
		{
			int x=q.front();
			q.pop();
			for(unsigned int i=0;i<edge[x].size();i++)
			{
				int y=edge[x][i];
				if(y==1)
				{
					ans=dis[x]+1;
					cout<<ans<<endl;
					return 0;
				}
				if(dis[y]) continue;
				dis[y]=dis[x]+1;
				q.push(y);
			}
		}
		
		cout<<"-1"<<endl;
		
	}
	return 0;
}
