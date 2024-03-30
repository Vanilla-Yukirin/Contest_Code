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


int n,x,y;


int a[N];
map<int,int>delta;
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
		cin>>n>>x>>y;
		int cnt=x;
		for(int i=1;i<=x;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+x+1);
		for(int i=2;i<=x;i++)
		{
			if(a[i]-a[i-1]==2) cnt++;
		}
		if(a[x]-a[1]==n-2) cnt++;
		
		delta.clear();
		int max_delta=0;
		for(int i=2;i<=x;i++)
		{
			delta[a[i]-a[i-1]]++;
			max_delta=max(max_delta,a[i]-a[i-1]);
		}
		delta[(a[1]-a[x])%n+n]++;
		auto it=delta.end();
		max_delta=it->first;
		
		for(it=delta.begin();it!=delta.end();it++)
		{
			if(it->first%2==0&&it->first>=4)
			{
				int cost=it->first/2-1,add=it->first-1;
				while(it->second&&y>=cost) it->second--,y-=cost,cnt+=add;
				if(it->second>0&&y>0)
				{
					while(it->second>0&&y>0) y--,cnt++;
				}
			}
		}
		for(it=delta.begin();it!=delta.end();it++)
		{
			if(it->first%2==1&&it->first>=3)
			{
				while(it->second--)
				{
					int cost=(it->first-1)/2;
					while(cost--&&y)
					{
						y--;
						cnt+=2;
						
					}
				}
			}
		}
		
		
		
		
		
		
		
		
		cout<<cnt-2<<endl;
		
		
		
	}
	return 0;
}
