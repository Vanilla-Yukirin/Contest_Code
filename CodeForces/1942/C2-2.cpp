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
set<int>s;
int a[N];

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
		s.clear();
		for(int i=1;i<=x;i++)
		{
			int xx;
			cin>>xx;
			s.insert(xx);
			a[i]=xx;
		}
		sort(a+1,a+1+x);
		int last=a[1];
		for(int i=1;i<=x&&y;i++)
		{
			int now=a[i];
			while(y&&(a[i%x+1]-now+n)%n>=3)
			{
				now+=2;
				s.insert(now);
//				cout<<"insert "<<now<<endl;
				y--;
			}
		}
		int cntx=0;
		for(auto it=s.begin();it!=s.end();it++)
		{
			cntx++;
			a[cntx]=*it;
		}
		int cnt=cntx;
		for(int i=2;i<=cntx;i++)
		{
			if(a[i]-a[i-1]==2) cnt++;
		}
		if(a[cntx]-a[1]==n-2) cnt++;
		cout<<cnt-2<<endl;
		
		
	}
	return 0;
}
