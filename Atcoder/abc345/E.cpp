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

priority_queue<int,vector<int>,greater<int> >q[N];
int n,k;

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
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int a,b;cin>>a>>b;
			q[a].push(b);
		}
		for(int j=1;j<=k;j++)
		{
			int mx=1;
			for(int i=1;i<=n;i++)
			{
				if(q[i].size()>q[mx].size()) mx=i;
				if(q[i].size()==q[mx].size())
				{
					if(q[i].top()<q[mx].top()) mx=i;
				}
			}
			q[mx].pop();
			cout<<"del "<<mx<<endl;
		}
		int mx=1;
		for(int i=1;i<=n;i++)
		{
			if(q[i].size()>q[mx].size()) mx=i;
		}
		if(q[mx].size()>(n-k+1)/2)
		{
			cout<<"-1"<<endl;
		}
		else{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				while(q[i].size()) sum+=q[i].top(),q[i].pop();
			}
			cout<<sum<<endl;
		}
		
	}
	return 0;
}
