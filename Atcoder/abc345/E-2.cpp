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
int cnt=1;
int n,k,kk;
int a[N],b[N];
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
			cin>>a[i]>>b[i];
		}
		q[1].push(b[1]);
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])
			{
				kk++;
			}
			else{
				cnt++;
			}
			q[cnt].push(b[i]);
		}
		if(kk>k)
		{
			cout<<-1<<endl;
		}
		else
		{
			while(k--)
			{
				int mx=1;
				debug
				for(int i=1;i<=cnt;i++)
				{
					debug
					if(q[mx].size())
					{
						if(q[i].size()&&q[i].top()<q[mx].top())
						{
							mx=i;
						}
					}
					else{
						if(q[i].size()) mx=i;
					}
					debug
				}
				cout<<"pop "<<mx<<" "<<q[mx].top()<<endl;
				q[mx].pop();
				
			}
			int sum=0;
			for(int i=1;i<=cnt;i++)
			{
				while(q[i].size()) sum+=q[i].top(),q[i].pop();
			}
			cout<<sum<<endl;
		}
		
	}
	return 0;
}
