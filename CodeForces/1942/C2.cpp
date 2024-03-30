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
		int cnt=x;
		s.clear();
		for(int i=1;i<=x;i++)
		{
			cin>>a[i];
			s.insert(a[i]);
		}
		sort(a+1,a+x+1);
		int last=a[x];
		auto it=s.begin();
		for(;it!=s.end()&&y>0;)
		{
			if((*it-last+n)%n>=3)
			{
				last+=2;
				if(last>n) last-=n;
				s.insert(last);
//				cout<<"insert "<<last<<endl;
				y--;
			}
			else last=*it,it++;
			
		}
		
		/*
		it=s.end();it--;
		while(y)
		{
			it=s.end();
			it--;
			if(*it+2>n) break;
			s.insert(*it+2);
			y--;
//			cout<<"insert "<<*it+2<<endl;
		}
		if(y&&s.find(n)==s.end()) s.insert(n),y--;
		if(y&&s.find(n-1)==s.end()) s.insert(n-1),y--;
		*/
		
		cnt=s.size();
		
		
		
		it=s.begin();
		int nn=0;
		for(int i=1;it!=s.end();it++,i++)
		{
			if(*it>n) break;
			a[i]=*it;
			nn=i;
//			cout<<a[i]<<" ";
		}
//		cout<<endl;
		for(int i=2;i<=nn;i++)
		{
			if(a[i]-a[i-1]==2) cnt++;
		}
		if(a[nn]-a[1]==n-2) cnt++;
		cout<<cnt-2<<endl;
		
		
		
	}
	return 0;
}
