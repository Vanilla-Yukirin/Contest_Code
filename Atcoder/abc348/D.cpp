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

int h,w,n;
pair<int,int>delta[4]={{0,1},{0,-1},{1,0},{-1,0}},S,T;
bool mp[300][300];
map<pair<int,int>,int>medicine;


struct node
{
	pair<int,int>p;
	int statu;
	map<pair<int,int>,int>medicine;
};



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
		cin>>h>>w;
		for(int i=1;i<=h;i++)
		{
			string str;cin>>str;
			for(int j=1;j<=w;j++)
			{
				if(str[j-1]=='#')
				{
					
				}
				else{
					mp[i][j]=1;
					if(str[j-1]=='S') S=make_pair(i,j);
					if(str[j-1]=='T') T=make_pair(i,j);
				}
			}
		}
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;cin>>a>>b>>c;
			medicine[make_pair(a,b)]=max(medicine[make_pair(a,b)],medicine[make_pair(a,b)]+c);
		}
		node x={S,0,medicine};
		queue<node>q;
		q.push(x);
		while(q.size())
		{
			x=q.front();
			q.pop();
			if(x.medicine.find(x.p)!=x.medicine.end())
			{
				x.statu+=x.medicine[x.p];
				x.medicine.erase(x.p);
			}
			if(x.statu<=0) continue;
			for(int t=0;t<4;t++)
			{
				node now=x;
				now.p.first+=delta[t].first;
				now.p.second+=delta[t].second;
				now.statu--;
				if(mp[now.p.first][now.p.second]) q.push()
				
				
				
			}
			
			
			
			
			
		}
		
		
		
		
		
	}
	return 0;
}
