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



#define N 200110

int n;
string str[2];

bool book[2][N];

set<pair<int,int>>s,nxt;
int delta[4][2]={0,1,0,-1,1,0,-1,0};

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
		cin>>str[0]>>str[1];
		str[0]=" "+str[0];
		str[1]=" "+str[1];
		
		s.insert(make_pair(0,1));
		book[0][1]=1;
		bool win=0;
		while(s.size())
		{
			int x,y,nx,ny;
			for(set<pair<int,int> >::iterator it=s.begin();it!=s.end();it++)
			{
				x=it->first;
				y=it->second;
//				cout<<"now="<<x<<" "<<y<<endl;
				if(x==1&&y==n)
				{
					win=1;
				}
				
				
				for(int t=0;t<4;t++)
				{
					nx=x+delta[t][0];
					ny=y+delta[t][1];
					
					if(nx<0||nx>1||ny<=0||ny>n) continue;
					if(str[nx][ny]=='<') ny--;
					else ny++;
					if(nx<0||nx>1||ny<=0||ny>n) continue;
					if(book[nx][ny]) continue;
					book[nx][ny]=1;
					nxt.insert(make_pair(nx,ny));
				}
			}
			s=nxt;
			nxt.clear();
			if(win) break;
		}
		if(win) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		
		
		for(int i=0;i<=n+3;i++)
		{
			book[0][i]=book[1][i]=0;
		}
		nxt.clear();
		s.clear();
	}
	return 0;
}
