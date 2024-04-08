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



#define N 300000



/*
3 2 3

3 9 6 5 7 1 10 4 8
2 8 5 4 6 0 9 3 7
0 2 3 4 5 6 7 8 9 

0 2 4
3 5 7
6 8 10

3 9 6 5 7 1 11 4 8
2 8 5 4 6 0 10 3 7
0 2 3 4 5 6 7 8 10



*/

int n,c,d;
int a[N];
int b[600];
int bb[600];
set<int>s;
bool judge(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(x>=b[i])
		{
			if(s.find(x-b[i])!=s.end())
			{
//				cout<<"x="<<x<<" - b["<<i<<"]="<<b[i]<<endl;
				return 1;
			}
		}
	}
	return 0;
}

int ans[100][100];

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
		cin>>n>>c>>d;
		ans[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			
			for(int j=2;j<=n;j++)
			{
				ans[i][j]=ans[i][j-1]+d;
				cout<<ans[i][j]<<" ";
			}
			ans[i+1][1]=ans[i][1]+c;
			cout<<ans[i+1][1]<<" ";
		}
		cout<<endl;
		
		int mn=1000000009;
		for(int i=1;i<=n*n;i++)
		{
			cin>>a[i];
			mn=min(mn,a[i]);
		}
		
		for(int i=1;i<=n*n;i++) a[i]-=mn,cout<<a[i]<<" ";
		b[1]=0;
		bb[1]=0;
		s.clear();
		s.insert(0);
		for(int i=2;i<=n;i++)
		{
			b[i]=b[i-1]+c;
			bb[i]=bb[i-1]+d;
			s.insert(bb[i]);
		}
		
		for(int i=1;i<=n;i++)
		{
			cout<<b[i]<<" ";
		}
			
		bool win=1;
		for(int i=1;i<=n*n;i++)
		{
			if(judge(a[i])==0) win=0;
			
		}
		if(win) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		
		
	}
	return 0;
}
