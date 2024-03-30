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


set<LL>s;

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
		LL n,a,b;
		cin>>n>>a>>b;
		LL last=0;
		while(n--)
		{
			LL x;cin>>x;
			x%=(a+b);
			s.insert(x);
			last=max(last,x);
		}
		last-=(a+b);
		LL delta=0;
		for(auto it=s.begin();it!=s.end();it++)
		{
			delta=max(delta,*it-last);
			last=*it;
		}
//		cout<<"delta="<<delta<<endl;
		
		if(delta-1>=b) cout<<"Yes";
		else cout<<"No";
		
		
		
	}
	return 0;
}
